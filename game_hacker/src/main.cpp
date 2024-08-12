#include <iostream>
#include <tchar.h>

import game_offsets;
import models;
import game_struct;
import raii;
import w32_lib;

int main(int argc, char **argv)
{
    DWORD csgoPid = hacklib::w32::FindProcessByName(_T("csgo.exe"));
    if (csgoPid == -1) {
        printf("Failed to find process\n");
        return 1;
    }
    printf("CSGO PID: %lu\n", csgoPid);
    PVOID serverBase = hacklib::w32::GetModuleBaseAddress(csgoPid, _T("server.dll"));
    if (serverBase == nullptr) {
        printf("Failed to find server.dll\n");
        return 1;
    }

    printf("Server.dll base address: %p\n", serverBase);
    hacklib::HandleRaii hCsgo(OpenProcess(PROCESS_ALL_ACCESS, FALSE, csgoPid));
    if (hCsgo.IsInvalid()) {
        printf("Failed to open process\n");
        return 1;
    }

    SIZE_T pPlayerList = (SIZE_T) serverBase + offset::OFFSET_PLAYER_LIST;

    for (int i = 0; i < 10; ++i) {
        SIZE_T memAddr = pPlayerList + i * sizeof(PlayerObjItem);

        PlayerObjItem playerObjItem;
        auto result = ReadProcessMemory(hCsgo.Get(), (PVOID) memAddr, &playerObjItem, sizeof(PlayerObjItem), nullptr);
        if (result == 0) {
            printf("Failed to read memory\n");
            return 1;
        }

        game_struct::UserObj pPlayer(hCsgo.Get(), playerObjItem.pPlayer, 230);

        printf("Player %d: %p\n", i, playerObjItem.pPlayer);
        printf("Player %d: %d\n", i, pPlayer.GetHealth());
        printf("Player %d: %f %f %f\n", i, pPlayer.GetX(), pPlayer.GetY(), pPlayer.GetZ());
    }
}

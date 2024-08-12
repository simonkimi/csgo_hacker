#include <iostream>
#include <tchar.h>

#include "raii.h"
#include "w32_lib.h"
#include "models.h"
#include "game_offsets.h"
#include "game_struct.h"


int main(int argc, char **argv)
{
    DWORD csgoPid = hackerlib::w32::findProcessByName(_T("csgo.exe"));
    if (csgoPid == -1) {
        printf("Failed to find process\n");
        return 1;
    }
    printf("CSGO PID: %lu\n", csgoPid);
    PVOID serverBase = hackerlib::w32::getModuleBaseAddress(csgoPid, _T("server.dll"));
    if (serverBase == nullptr) {
        printf("Failed to find server.dll\n");
        return 1;
    }

    printf("Server.dll base address: %p\n", serverBase);
    hackerlib::HandleRaii hCsgo(OpenProcess(PROCESS_ALL_ACCESS, FALSE, csgoPid));
    if (hCsgo.isInvalid()) {
        printf("Failed to open process\n");
        return 1;
    }

    SIZE_T pPlayerList = (SIZE_T) serverBase + game_offsets::OFFSET_PLAYER_LIST;

    for (int i = 0; i < 10; ++i) {
        SIZE_T memAddr = pPlayerList + i * sizeof(PlayerObjItem);

        PlayerObjItem playerObjItem;
        auto result = ReadProcessMemory(hCsgo.get(), (PVOID) memAddr, &playerObjItem, sizeof(PlayerObjItem), nullptr);
        if (result == 0) {
            printf("Failed to read memory\n");
            return 1;
        }

        game_struct::UserObj pPlayer(hCsgo.get(), playerObjItem.pPlayer, 230);

        printf("Player %d: %p\n", i, playerObjItem.pPlayer);
        printf("Player %d: %d\n", i, pPlayer.getHealth());
        printf("Player %d: %f %f %f\n", i, pPlayer.getX(), pPlayer.getY(), pPlayer.getZ());
    }
}

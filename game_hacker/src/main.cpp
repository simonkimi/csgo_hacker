#include <iostream>
#include <tchar.h>
#include "win32_helper.h"
#include "raii.h"
#include "model.h"


int main(int argc, char **argv)
{
    DWORD csgoPid = FindProcessByName(_T("csgo.exe"));
    PVOID serverBase = GetModuleBaseAddress(csgoPid, _T("server.dll"));
    printf("CSGO PID: %lu\n", csgoPid);
    printf("Server.dll base address: %p\n", serverBase);

    HandleRaii hCsgo(OpenProcess(PROCESS_ALL_ACCESS, FALSE, csgoPid));
    if (hCsgo.IsInvalid()) {
        printf("Failed to open process\n");
        return 1;
    }

    SIZE_T pPlayerList = (SIZE_T) serverBase + 0xAB05D4;
    
    for (int i = 0; i < 10; ++i) {
        auto memAddr = pPlayerList + i * sizeof(PlayerObjItem);
        PlayerObjItem playerObjItem;
        auto result = ReadProcessMemory(hCsgo.Get(), (PVOID) memAddr, &playerObjItem, sizeof(PlayerObjItem), nullptr);
        if (result == 0) {
            printf("Failed to read memory\n");
            return 1;
        }
 
        PlayerObj pPlayer;
        result = ReadProcessMemory(hCsgo.Get(), playerObjItem.pPlayer, &pPlayer, sizeof(PlayerObj), nullptr);
        if (result == 0) {
            printf("Failed to read memory\n");
            return 1;
        }
        
        printf("Player %d: %p\n", i, playerObjItem.pPlayer);
        printf("Player %d: %d\n", i, pPlayer.health);
    }
}

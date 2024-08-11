#include <raii.h>
#include "win32_helper.h"


DWORD FindProcessByName(LPCTSTR processName)
{
    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);
    HandleRaii hSnapshot(::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL));

    if (hSnapshot.IsInvalid()) {
        return -1;
    }

    if (::Process32First(hSnapshot.Get(), &pe32)) {
        do {
            if (lstrcmpi(pe32.szExeFile, processName) == 0) {
                return pe32.th32ProcessID;
            }
        } while (::Process32Next(hSnapshot.Get(), &pe32));
    }
    return -1;
}

PVOID GetModuleBaseAddress(DWORD dwPid, LPCTSTR moduleName)
{
    MODULEENTRY32 me32;
    me32.dwSize = sizeof(MODULEENTRY32);
    HandleRaii hSnapshot(::CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwPid));

    if (hSnapshot.IsInvalid()) {
        return nullptr;
    }

    if (::Module32First(hSnapshot.Get(), &me32)) {
        do {
            if (lstrcmpi(me32.szModule, moduleName) == 0) {
                return me32.modBaseAddr;
            }
        } while (::Module32Next(hSnapshot.Get(), &me32));
    }
    return nullptr;
}
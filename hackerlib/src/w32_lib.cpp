#include "w32_lib.h"
#include "raii.h"

DWORD hackerlib::w32::findProcessByName(LPCTSTR processName)
{
    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);
    HandleRaii hSnapshot(::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL));

    if (hSnapshot.isInvalid()) {
        return -1;
    }

    if (::Process32First(hSnapshot.get(), &pe32)) {
        do {
            if (lstrcmpi(pe32.szExeFile, processName) == 0) {
                return pe32.th32ProcessID;
            }
        } while (::Process32Next(hSnapshot.get(), &pe32));
    }
    return -1;
}

PVOID hackerlib::w32::getModuleBaseAddress(DWORD dwPid, LPCTSTR moduleName)
{
    MODULEENTRY32 me32;
    me32.dwSize = sizeof(MODULEENTRY32);
    HandleRaii hSnapshot(::CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwPid));

    if (hSnapshot.isInvalid()) {
        return nullptr;
    }

    if (::Module32First(hSnapshot.get(), &me32)) {
        do {
            if (lstrcmpi(me32.szModule, moduleName) == 0) {
                return me32.modBaseAddr;
            }
        } while (::Module32Next(hSnapshot.get(), &me32));
    }
    return nullptr;
}
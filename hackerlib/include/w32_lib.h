#include "Windows.h"
#include "TlHelp32.h"

namespace hackerlib::w32 {

DWORD findProcessByName(LPCTSTR processName);

PVOID getModuleBaseAddress(DWORD dwPid, LPCTSTR moduleName);

}


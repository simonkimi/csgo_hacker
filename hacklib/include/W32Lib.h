#pragma once

#include "Windows.h"


namespace hacklib {
namespace w32 {
DWORD FindProcessByName(LPCTSTR processName);

PVOID GetModuleBaseAddress(DWORD dwPid, LPCTSTR moduleName);
}
}
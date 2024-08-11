#pragma once

#include "pch.h"
#include <TlHelp32.h>


DWORD FindProcessByName(LPCTSTR processName);

PVOID GetModuleBaseAddress(DWORD dwPid, LPCTSTR moduleName);
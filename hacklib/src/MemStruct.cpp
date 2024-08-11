#include "MemStruct.h"

MemStruct::MemStruct(HANDLE pHandle, PVOID address, SIZE_T size)
{
    data = new BYTE[size];
    BOOL status = ReadProcessMemory(pHandle, address, data, size, nullptr);
    if (!status) {
        delete[] data;
        data = nullptr;
        throw std::runtime_error("Failed to read memory");
    }
}

MemStruct::~MemStruct()
{
    delete[] data;
}

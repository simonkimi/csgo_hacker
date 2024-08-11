#pragma once

#include <stdexcept>
#include "Windows.h"


class MemStruct {
public:
    explicit MemStruct(HANDLE pHandle, PVOID address, SIZE_T size);

    ~MemStruct();

protected:

    BYTE GetByte(size_t offset)
    {
        return data[offset];
    }

    INT GetInt(size_t offset)
    {
        return *reinterpret_cast<INT *>(&data[offset]);
    }

    PVOID GetPtr(size_t offset)
    {
        return *reinterpret_cast<PVOID *>(&data[offset]);
    }

    LONGLONG GetLong(size_t offset)
    {
        return *reinterpret_cast<LONGLONG *>(&data[offset]);
    }

    FLOAT GetFloat(size_t offset)
    {
        return *reinterpret_cast<FLOAT *>(&data[offset]);
    }

    DOUBLE GetDouble(size_t offset)
    {
        return *reinterpret_cast<DOUBLE *>(&data[offset]);
    }

private:
    BYTE *data;
};

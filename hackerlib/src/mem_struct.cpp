#include "mem_struct.h"

namespace hackerlib {
MemStruct::MemStruct(HANDLE pHandle, PVOID address, SIZE_T size)
{
    data_buf_ = new BYTE[size];
    BOOL status = ReadProcessMemory(pHandle, address, data_buf_, size, nullptr);
    if (!status) {
        delete[] data_buf_;
        data_buf_ = nullptr;
        throw std::runtime_error("Failed to read memory");
    }
}

MemStruct::~MemStruct()
{
    delete[] data_buf_;
}

BYTE MemStruct::getByte(SIZE_T offset)
{
    return data_buf_[offset];
}

INT MemStruct::getInt(SIZE_T offset)
{
    return *reinterpret_cast<INT *>(&data_buf_[offset]);
}

PVOID MemStruct::getPtr(SIZE_T offset)
{
    return *reinterpret_cast<PVOID *>(&data_buf_[offset]);
}

LONGLONG MemStruct::getLong(SIZE_T offset)
{
    return *reinterpret_cast<LONGLONG *>(&data_buf_[offset]);
}

FLOAT MemStruct::getFloat(SIZE_T offset)
{
    return *reinterpret_cast<FLOAT *>(&data_buf_[offset]);
}

DOUBLE MemStruct::getDouble(SIZE_T offset)
{
    return *reinterpret_cast<DOUBLE *>(&data_buf_[offset]);
}

}

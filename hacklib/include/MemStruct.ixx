#include "Windows.h"
#include <stdexcept>

export module mem_struct;


export namespace hacklib {
class MemStruct {
public:
    explicit MemStruct(HANDLE pHandle, PVOID address, SIZE_T size);

    ~MemStruct();

protected:

    BYTE GetByte(size_t offset);

    INT GetInt(size_t offset);

    PVOID GetPtr(size_t offset);

    LONGLONG GetLong(size_t offset);

    FLOAT GetFloat(size_t offset);

    DOUBLE GetDouble(size_t offset);

private:
    BYTE *data;
};
}


#pragma region impl


namespace hacklib {
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

BYTE MemStruct::GetByte(size_t offset)
{
    return data[offset];
}

INT MemStruct::GetInt(size_t offset)
{
    return *reinterpret_cast<INT *>(&data[offset]);
}

PVOID MemStruct::GetPtr(size_t offset)
{
    return *reinterpret_cast<PVOID *>(&data[offset]);
}

LONGLONG MemStruct::GetLong(size_t offset)
{
    return *reinterpret_cast<LONGLONG *>(&data[offset]);
}

FLOAT MemStruct::GetFloat(size_t offset)
{
    return *reinterpret_cast<FLOAT *>(&data[offset]);
}

DOUBLE MemStruct::GetDouble(size_t offset)
{
    return *reinterpret_cast<DOUBLE *>(&data[offset]);
}

}

#pragma endregion
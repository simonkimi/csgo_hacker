#pragma once


#include <mem_struct.h>

namespace game_struct {
class UserObj : hackerlib::MemStruct {
public:
    explicit UserObj(HANDLE pHandle, PVOID address, SIZE_T size) : MemStruct(pHandle, address, size) {}

    INT getHealth();

    FLOAT getX();

    FLOAT getY();

    FLOAT getZ();
};
}





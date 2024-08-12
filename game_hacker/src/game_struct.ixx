export module game_struct;

import game_offsets;
import mem_struct;


export namespace game_struct {
class UserObj : hacklib::MemStruct {
public:
    explicit UserObj(HANDLE pHandle, PVOID address, SIZE_T size) : MemStruct(pHandle, address, size) {}

    INT GetHealth()
    {
        return GetInt(offset::OFFSET_PLAYER_HEALTH);
    }

    FLOAT GetX()
    {
        return GetFloat(offset::OFFSET_PLAYER_X);
    }

    FLOAT GetY()
    {
        return GetFloat(offset::OFFSET_PLAYER_Y);
    }

    FLOAT GetZ()
    {
        return GetFloat(offset::OFFSET_PLAYER_Z);
    }
};
}





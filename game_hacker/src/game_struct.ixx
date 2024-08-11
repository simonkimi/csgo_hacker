export module game_struct;

import <game_offsets>;





namespace game_struct {
class UserObj : public MemStruct {
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





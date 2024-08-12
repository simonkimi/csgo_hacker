#pragma once

#include "game_struct.h"
#include "game_offsets.h"


namespace game_struct {


INT UserObj::getHealth()
{
    return getInt(game_offsets::OFFSET_PLAYER_HEALTH);
}

FLOAT UserObj::getX()
{
    return getFloat(game_offsets::OFFSET_PLAYER_X);
}

FLOAT UserObj::getY()
{
    return getFloat(game_offsets::OFFSET_PLAYER_Y);
}

FLOAT UserObj::getZ()
{
    return getFloat(game_offsets::OFFSET_PLAYER_Z);
}


}
#pragma once

#include "Windows.h"

namespace game_offsets {
const int OFFSET_PLAYER_LIST = 0xAB05D4;

const SIZE_T OFFSET_PLAYER_HEALTH = 0x230;
const SIZE_T OFFSET_PLAYER_X = 0x1dc;
const SIZE_T OFFSET_PLAYER_Y = OFFSET_PLAYER_X + sizeof(float);
const SIZE_T OFFSET_PLAYER_Z = OFFSET_PLAYER_X + 2 * sizeof(float);
}


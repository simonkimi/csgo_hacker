export module game_offsets;


export namespace offset {
const int OFFSET_PLAYER_LIST = 0xAB05D4;

const size_t OFFSET_PLAYER_HEALTH = 0x230;
const size_t OFFSET_PLAYER_X = 0x1dc;
const size_t OFFSET_PLAYER_Y = OFFSET_PLAYER_X + sizeof(float);
const size_t OFFSET_PLAYER_Z = OFFSET_PLAYER_X + 2 * sizeof(float);
}


export module models;


#include "Windows.h"


export typedef struct PlayerObjItem {
    PVOID pPlayer;
    [[maybe_unused]] BYTE padding[5 * 4];
} PlayerObjItem;



#pragma once

#include "Windows.h"


typedef struct PlayerObjItem {
    PVOID pPlayer;
    BYTE padding[5 * 4];
} PlayerObjItem;


typedef struct PlayerObj {
    BYTE padding[0x230];
    int health;
} PlayerObj;
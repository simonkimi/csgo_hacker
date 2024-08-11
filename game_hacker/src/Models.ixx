export module models;

#include "Tools.h"
#include "Windows.h"


export typedef struct PlayerObjItem {
    PVOID pPlayer;
    FIELD_PADDING(0, 5 * 4);
} PlayerObjItem;



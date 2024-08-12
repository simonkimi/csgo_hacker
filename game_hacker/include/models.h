#include "Windows.h"

typedef struct PlayerObjItem {
    PVOID pPlayer;
    [[maybe_unused]] BYTE padding[5 * 4];
} PlayerObjItem;



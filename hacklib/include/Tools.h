#pragma once

#define FIELD_PADDING(index, length) __attribute__((unused)) BYTE padding_##index[length]
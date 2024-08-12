#include "Windows.h"
#include <stdexcept>


namespace hackerlib {
class MemStruct {
public:
    explicit MemStruct(HANDLE pHandle, PVOID address, SIZE_T size);

    ~MemStruct();

protected:

    BYTE getByte(SIZE_T offset);

    INT getInt(SIZE_T offset);

    PVOID getPtr(SIZE_T offset);

    LONGLONG getLong(SIZE_T offset);

    FLOAT getFloat(SIZE_T offset);

    DOUBLE getDouble(SIZE_T offset);

private:
    BYTE *data_buf_;
};
}


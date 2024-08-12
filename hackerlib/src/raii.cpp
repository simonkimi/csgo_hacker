#include "raii.h"

namespace hackerlib {

HandleRaii::HandleRaii(HANDLE handle) : handle_(handle) {}

HandleRaii::~HandleRaii()
{
    if (!isInvalid()) {
        ::CloseHandle(handle_);
    }
}

HANDLE HandleRaii::get() const
{
    return handle_;

}

bool HandleRaii::isInvalid() const
{
    return handle_ == INVALID_HANDLE_VALUE || handle_ == nullptr;
}

}
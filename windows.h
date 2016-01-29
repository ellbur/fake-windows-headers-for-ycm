
#pragma once

#include <inttypes.h>

typedef int HANDLE;

HANDLE CreateMutex(void*, bool, void*);
uintptr_t _beginthread(void(*start_address)(void *), unsigned, void*);


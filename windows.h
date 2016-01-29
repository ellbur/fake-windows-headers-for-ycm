
#pragma once

#include <inttypes.h>

typedef int HANDLE;

HANDLE CreateMutex(void*, bool, void*);
uintptr_t _beginthread(void(*start_address)(void *), unsigned, void*);

void Sleep(int);
void SetEvent(HANDLE);
HANDLE CreateEvent(void*, bool, bool, void*);

#define INFINITE 0
#define FALSE 0
#define TRUE 1

void WaitForSingleObject(HANDLE, int);



#pragma once

#include "winsock2.h"

#include <inttypes.h>
#include <stdio.h>
#include <errno.h>

#include <locale.h>

typedef int errno_t;

#ifdef UNICODE
typedef wchar_t TCHAR;
#else
typedef char TCHAR;
#endif


typedef const void* LPCVOID;

typedef bool BOOL;
typedef long LONG;
typedef unsigned long u_long;

typedef TCHAR const* LPCTSTR;
typedef TCHAR * LPTSTR;

typedef void* HANDLE;
typedef void* HMODULE;

typedef uint32_t DWORD;

typedef unsigned int UINT;
typedef int INT;

typedef bool *LPBOOL;
typedef long *LPLONG;

typedef char *LPSTR;
typedef char const *LPCSTR;
typedef wchar_t const *LPCWSTR;
typedef wchar_t *LPWSTR;

#define __int64 long long
#define __w64

#define __stdcall
#define APIENTRY

#define _In_
#define _In_opt_
#define _Out_
#define _Out_opt_
#define WINAPI
#define __in
#define __out

#define MAX_PATH 256

HANDLE CreateMutex(void*, bool, void*);
uintptr_t _beginthread(void(*start_address)(void *), unsigned, void*);

#define THREAD_PRIORITY_HIGHEST 0
#define THREAD_PRIORITY_BELOW_NORMAL 0

BOOL WINAPI SetThreadPriority(
  _In_ HANDLE hThread,
  _In_ int    nPriority
);

uintptr_t _beginthreadex(
   void *security,
   unsigned stack_size,
   unsigned ( __stdcall *start_address )( void * ),
   void *arglist,
   unsigned initflag,
   unsigned *thrdaddr
);

void Sleep(int);
void SetEvent(HANDLE);
HANDLE CreateEvent(void*, bool, bool, void*);

#define INFINITE 0
#define FALSE 0
#define TRUE 1

int WaitForSingleObject(HANDLE, int);

DWORD WINAPI GetPrivateProfileString(
  _In_  LPCTSTR lpAppName,
  _In_  LPCTSTR lpKeyName,
  _In_  LPCTSTR lpDefault,
  _Out_ LPTSTR  lpReturnedString,
  _In_  DWORD   nSize,
  _In_  LPCTSTR lpFileName
);

HANDLE WINAPI CreateSemaphore(
  _In_opt_ void*                 lpSemaphoreAttributes,
  _In_     LONG                  lInitialCount,
  _In_     LONG                  lMaximumCount,
  _In_opt_ LPCTSTR               lpName
);

UINT WINAPI GetPrivateProfileInt(
  _In_ LPCTSTR lpAppName,
  _In_ LPCTSTR lpKeyName,
  _In_ INT     nDefault,
  _In_ LPCTSTR lpFileName
);

void CloseHandle(HANDLE);
void ResetEvent(HANDLE);
void ReleaseMutex(HANDLE);

#define CP_ACP 0

int WideCharToMultiByte(
  _In_      UINT    CodePage,
  _In_      DWORD   dwFlags,
  _In_      LPCWSTR lpWideCharStr,
  _In_      int     cchWideChar,
  _Out_opt_ LPSTR   lpMultiByteStr,
  _In_      int     cbMultiByte,
  _In_opt_  LPCSTR  lpDefaultChar,
  _Out_opt_ LPBOOL  lpUsedDefaultChar
);

int sprintf_s(
   char *buffer,
   size_t sizeOfBuffer,
   const char *format,
   ...
);
int _sprintf_s_l(
   char *buffer,
   size_t sizeOfBuffer,
   const char *format,
   locale_t locale,
   ...
);
int swprintf_s(
   wchar_t *buffer,
   size_t sizeOfBuffer,
   const wchar_t *format,
   ...
);
int _swprintf_s_l(
   wchar_t *buffer,
   size_t sizeOfBuffer,
   const wchar_t *format,
   locale_t locale,
   ...
);

#ifdef __cplusplus
template <size_t size>
int sprintf_s(
   char (&buffer)[size],
   const char *format,
   ...
); // C++ only

template <size_t size>
int swprintf_s(
   wchar_t (&buffer)[size],
   const wchar_t *format,
   ...
); // C++ only
#endif

errno_t strcpy_s(
   char *strDestination,
   size_t numberOfElements,
   const char *strSource
);

errno_t wcscpy_s(
   wchar_t *strDestination,
   size_t numberOfElements,
   const wchar_t *strSource
);

errno_t _mbscpy_s(
   unsigned char *strDestination,
   size_t numberOfElements,
   const unsigned char *strSource
);

#ifdef __cplusplus
template <size_t size>
errno_t strcpy_s(
   char (&strDestination)[size],
   const char *strSource
); // C++ only

template <size_t size>
errno_t wcscpy_s(
   wchar_t (&strDestination)[size],
   const wchar_t *strSource
); // C++ only

template <size_t size>
errno_t _mbscpy_s(
   unsigned char (&strDestination)[size],
   const unsigned char *strSource
); // C++ only
#endif

errno_t fopen_s(
   FILE** pFile,
   const char *filename,
   const char *mode
);

errno_t _wfopen_s(
   FILE** pFile,
   const wchar_t *filename,
   const wchar_t *mode
);

#define WAIT_OBJECT_0 0

void * _aligned_malloc(
    size_t size,
    size_t alignment
);

BOOL WINAPI ReleaseSemaphore(
  _In_      HANDLE hSemaphore,
  _In_      LONG   lReleaseCount,
  _Out_opt_ LPLONG lpPreviousCount
);

DWORD WINAPI WaitForMultipleObjects(
  _In_       DWORD  nCount,
  _In_ const HANDLE *lpHandles,
  _In_       BOOL   bWaitAll,
  _In_       DWORD  dwMilliseconds
);

HMODULE GetModuleHandleA(
  LPCSTR lpModuleName
);

DWORD WINAPI GetModuleFileName(
  _In_opt_ HMODULE hModule,
  _Out_    LPTSTR  lpFilename,
  _In_     DWORD   nSize
);

errno_t strcat_s(
   char *strDestination,
   size_t numberOfElements,
   const char *strSource
);
errno_t wcscat_s(
   wchar_t *strDestination,
   size_t numberOfElements,
   const wchar_t *strSource
);
errno_t _mbscat_s(
   unsigned char *strDestination,
   size_t numberOfElements,
   const unsigned char *strSource
);

#ifdef __cplusplus
template <size_t size>
errno_t strcat_s(
   char (&strDestination)[size],
   const char *strSource
); // C++ only
template <size_t size>
errno_t wcscat_s(
   wchar_t (&strDestination)[size],
   const wchar_t *strSource
); // C++ only
template <size_t size>
errno_t _mbscat_s(
   unsigned char (&strDestination)[size],
   const unsigned char *strSource
); // C++ only
#endif

#define _MAX_PATH 1024

wchar_t *_wgetenv(
   const wchar_t *varname
);

int _snprintf_s(
   char *buffer,
   size_t sizeOfBuffer,
   size_t count,
   const char *format,
   ...
);
int _snprintf_s_l(
   char *buffer,
   size_t sizeOfBuffer,
   size_t count,
   const char *format,
   locale_t locale,
   ...
);
int _snwprintf_s(
   wchar_t *buffer,
   size_t sizeOfBuffer,
   size_t count,
   const wchar_t *format,
   ...
);
int _snwprintf_s_l(
   wchar_t *buffer,
   size_t sizeOfBuffer,
   size_t count,
   const wchar_t *format,
   locale_t locale,
   ...
);

#ifdef __cplusplus
template <size_t size>
int _snprintf_s(
   char (&buffer)[size],
   size_t count,
   const char *format,
   ...
); // C++ only

template <size_t size>
int _snwprintf_s(
   wchar_t (&buffer)[size],
   size_t count,
   const wchar_t *format,
   ...
); // C++ only
#endif

typedef int WORD;

#define MAKEWORD(x, y) 0

#define FAR



DWORD FormatMessage(
  DWORD   dwFlags,
  LPCVOID lpSource,
  DWORD   dwMessageId,
  DWORD   dwLanguageId,
  LPTSTR  lpBuffer,
  DWORD   nSize,
  va_list *Arguments
);


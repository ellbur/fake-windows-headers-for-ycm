
#pragma once

#include "windows.h"

#include <string.h>


typedef int SOCKET;

int send(SOCKET, char const*, int, int);
int recv(SOCKET, char const*, int, int);

#define WSAAPI

#define SOCKET_ERROR 0

int WSAGetLastError();

#define WSAEWOULDBLOCK (-1)

#define AF_INET 0
#define SOCK_STREAM 0

#define FORMAT_MESSAGE_ALLOCATE_BUFFER 0
#define FORMAT_MESSAGE_FROM_SYSTEM 0
#define IPPROTO_TCP 0
#define INVALID_SOCKET 0
#define INADDR_ANY 0


#define SOMAXCONN 0

#define WSADESCRIPTION_LEN 256
#define WSASYSSTATUS_LEN 255

#define NO_ERROR 0

struct WSAData {
  WORD wVersion;
  WORD wHighVersion;
  char szDescription[WSADESCRIPTION_LEN+1];
  char szSystemStatus[WSASYSSTATUS_LEN+1];
  unsigned short iMaxSockets;
  unsigned short iMaxUdpDg;
  char FAR* lpVendorInfo;
};

typedef WSAData* LPWSADATA;

int WSAStartup(
  _In_  WORD      wVersionRequested,
  _Out_ LPWSADATA lpWSAData
);



int WSACleanup();

struct sin_addr_t {
  uint32_t s_addr;
};

struct sockaddr_in {
  int sin_family;
  int sin_port;
  sin_addr_t sin_addr;
};

unsigned short htons(unsigned short x);

#define FIONBIO 0

void closesocket(SOCKET);

int inet_addr(char const*);

SOCKET socket(int, int, int);

struct sockaddr {
};

int ioctlsocket(
  SOCKET s,
  long   cmd,
  DWORD *argp
);



int bind(
  __in  SOCKET s,
  __in  const struct sockaddr *name,
  __in  int namelen
);


int WSAAPI listen(
 SOCKET s,
 int    backlog
);

int WSAAPI connect(
   SOCKET         s,
   const sockaddr *name,
   size_t namelen
);

#define WINSOCK_API_LINKAGE

WINSOCK_API_LINKAGE SOCKET WSAAPI accept(
   SOCKET   s,
   sockaddr *addr,
   int      *addrlen
);

int recv(
   SOCKET s,
   char   *buf,
   int    len,
   int    flags
);

int WSAAPI send(
   SOCKET     s,
   const char *buf,
   int        len,
   int        flags
);

#define PCTSTR const char*
#define PVOID void*

INT WSAAPI inet_pton(
  __in   INT  Family,
  __in   PCTSTR pszAddrString,
  __out  PVOID pAddrBuf
);

#define _CRTDBG_ALLOC_MEM_DF 0
#define _CRTDBG_LEAK_CHECK_DF 0



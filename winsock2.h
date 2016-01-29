
#pragma once

typedef int SOCKET;

int send(SOCKET, char const*, int, int);
int recv(SOCKET, char const*, int, int);

#define SOCKET_ERROR (-1)

int WSAGetLastError();

#define WSAEWOULDBLOCK (-1)

#define AF_INET 0
#define SOCK_STREAM 0

struct sin_addr_t {
  char s_addr[4];
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

int connect(SOCKET, struct sockaddr *, size_t);

void ioctlsocket(SOCKET, int, void*);


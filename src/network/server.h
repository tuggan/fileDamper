// License shiet goes here i think.

#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <error.h>

struct netSrvr {
    struct sockaddr_in inAddr;
};

struct netSrvr setupListen(int lPort);





















// License shiet goes here i think.

#ifndef SERVER_H
#define SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <error.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define BACKLOG 10

struct networkServer {
    struct addrinfo addr;
    struct addrinfo *info;
    int sockfd;
};

typedef struct networkServer **netSrv;

netSrv nets_setupListen();

void nets_bindSocket(netSrv net);

int nets_listenForNew(netSrv net);

int nets_rec(int socket, char *buf, int buflen);

void nets_close(netSrv net);

#endif

















#include "server.h"

netSrv nets_setupListen() {
    char* port = "37300";
    int status;

    struct networkServer *hints = calloc(1 ,sizeof(struct networkServer));

    memset(hints, 0, sizeof(struct networkServer));

    // @TODO This should not be static!
    hints->addr.ai_family = AF_UNSPEC; // Dont care wheter IPv4 or v6
    hints->addr.ai_socktype = SOCK_STREAM; // Set TCP
    hints->addr.ai_flags = AI_PASSIVE; // Fill in ip for me

    status = getaddrinfo(NULL, port, &(hints->addr), &hints->info);

    if(status != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    netSrv ret = malloc(sizeof(struct networkServer*));
    (*ret) = hints;
    return ret;
}

void nets_bindSocket(netSrv net) {
    int s;

    s = socket((*net)->info->ai_family,
               (*net)->info->ai_socktype,
               (*net)->info->ai_protocol);

    if(s == -1) {
        fprintf(stderr, "socket error: %s\n", gai_strerror(s));
        exit(1);
    }

    // @TODO error chocking on socket.

    (*net)->sockfd = s;

    int b = bind((*net)->sockfd,
                 (*net)->info->ai_addr,
                 (*net)->info->ai_addrlen);

    if( b == -1) {
        fprintf(stderr, "bind error: %s\n", gai_strerror(b));
        exit(1);
    }

    // @TODO error check bind!

}

int nets_listenForNew(netSrv net) {
    listen((*net)->sockfd, BACKLOG);

    struct sockaddr_storage their_addr;
    socklen_t addr_size;

    addr_size = sizeof(their_addr);
    int newfd = accept((*net)->sockfd, (struct sockaddr *)&their_addr, &addr_size);
    return newfd;
}

int nets_rec(int socket, char *buf, int buflen) {
    return recv(socket, buf, buflen, 0);
}

int nets_send(int socket, char *buf, int buflen) {
    // @TODO Change signals...
    return send(socket, buf, buflen, MSG_NOSIGNAL);
}

void nets_close(netSrv net) {
    freeaddrinfo((*net)->info);
    free(*net);
    free(net);
}




















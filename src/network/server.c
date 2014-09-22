/**
  * This is a udp server thingie that can handle only one client.
  *
  * A lot of orrors, i have no idea what yet tho, or if im using it right.
  * 1 - Could not create socket.
  * 2 - Could not bind socket.
  */
#include "server.h"

struct netSrvr setupListen(int lPort) {
    int fd;

// Open a socket of type udp (SOCK_DGRAM)
    fd = socket(AF_INET, SOCK_DGRAM, 0);

    if(fd < 0) {
        error(1, 0, "Could not open socket.");
    }

    struct netSrvr addr;

    memset((char *)&addr.inAddr, 0, sizeof(addr.inAddr));
    addr.inAddr.sin_family = AF_INET;
    addr.inAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.inAddr.sin_port = htons(lPort);

    if (bind(fd, (struct sockaddr *)&addr.inAddr, sizeof(addr.inAddr)) < 0) {
        error(2, 0, "Could not bind socket.");
    }

    return addr;
}





















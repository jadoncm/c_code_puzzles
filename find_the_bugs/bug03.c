/* What is wrong with this code? */

#include <stdio.h>

/* function does something with the buffer */
void
do_something_with_buffer(char * buf, size_t len) {
    return;
}

/* function connects to a server */
int
open_socket(void) {
    return;
}

int
main(int argc, char ** argv) {
    char   buf[1024];
    size_t bytes_recvd;
    int    fd;

    if ((fd = open_socket()) < 0) {
        return -1;
    }

    if ((bytes_recvd = recv(fd, buf, sizeof(buf), 0)) < 0) {
        perror("recv");
        return -1;
    }

    do_something_with_buffer(buf, bytes_recvd);

    return 0;
}


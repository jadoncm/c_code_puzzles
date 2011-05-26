/* why does this program cause a segfault? */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

char *
give_me_data(void) {
    char * data;

    data = alloca(1024);

    strncpy(data, "hello, world", 1024);

    return data;
}

int
main(int argc, char ** argv) {
    char * data = give_me_data();

    printf("%s\n", data);
    free(data);

    return 0;
}


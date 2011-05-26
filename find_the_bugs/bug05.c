/* Why does this code not compile? What is the fix? (There are two ways, but
 * only one is optimal) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

#define inline_loop(string)              \
    int i;                               \
    const char * ptr = string;           \
    for (i = 0; i < *ptr != '\0'; i++) { \
        printf("%c\n", *ptr++);          \
    }

int
main(int argc, char ** argv) {
    if (argc > 2) {
        inline_loop(argv[1]);
    } else{
        printf("no arguments..\n");
    }

    return 0;
}


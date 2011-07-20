/* something seems fishy, but is it? */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

#define MAJOR_VERSION 2
#define MINOR_VERSION 0
#define MICRO_VERSION 1

typedef struct version {
    int major;
    int minor;
    int micro;
} version_t;

version_t
foobar_version_info(void) {
    version_t ver;

    ver.major = MAJOR_VERSION;
    ver.minor = MINOR_VERSION;
    ver.micro = MICRO_VERSION;

    return ver;
}

int
main(int argc, char ** argv) {
    version_t version;

    version = foobar_version_info();

    printf("v%d.%d.%d\n",
           version.major,
           version.minor,
           version.micro);


    return 0;
}


/* Without compiling, what does this print? */
#include <stdio.h>

const char *
example(int num) {
    const char * str;

    switch (num) {
        case 1:
            str = "one";
        case 2:
            str = "two";
        case 3:
            str = "three";
        default:
            str = "none";
    }

    return str;
}

int
main(int argc, char ** argv) {
    printf("%s\n", example(2));

    return 0;
}


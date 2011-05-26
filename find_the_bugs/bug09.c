#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

int
upcastoverflow_check(int8_t a, uint8_t b) {
    /* function to make sure unsigned b can be added to signed a without overflowing */

    if ((a + b) < a) {
        return -1;
    }

    return 0;
}

int
main(int argc, char ** argv) {
    /* sum a and b */
    int8_t  a = INT8_MAX - 3;
    uint8_t b = 5;

    if (upcastoverflow_check(a, b) < 0) {
        printf("a would be overflowed!\n");
        exit(1);
    }

    a += b;

    return 0;
}


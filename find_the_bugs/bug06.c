/* What is the output? */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

int main(int argc, char **argv) {
    int one = 1;
    int two = 2;

    one = 2;   /* the minimum amount of data
    two = 3;   /* the maxiumum amount of data */

    printf(" one + two = %d\n", one, two);
    return 0;
}


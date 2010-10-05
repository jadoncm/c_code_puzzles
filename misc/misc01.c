/* what does the check() function do? */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

#define error -1
#define ok     0

int check(uint16_t a, uint16_t b) {
    if ((a + b) < a) {
        return error;
    }

    return ok;
}

uint16_t sum(uint16_t a, uint16_t b, int *status) {
    if (check(a, b) == error) {
        *status = error;
        return 0;
    }
    a += b;

    *status = ok;
    return a;
}

int main(int argc, char **argv) {
    uint16_t num1;
    uint16_t num2;
    uint16_t summed;
    int      status;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <num1> <num2>\n", argv[0]);
        return -1;
    }

    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);

    if (num2 == 0 || num1 == 0) {
        fprintf(stderr, "Both arguments must be a positive number\n");
        return -1;
    }

    summed = sum(num1, num2, &status);

    if (status == error) {
        return -1;
    }

    printf("Sum of %d and %d == %d\n", num1, num2, summed);

    return 0;
}

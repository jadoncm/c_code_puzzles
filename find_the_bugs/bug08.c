/* something here is sinister, figure it out! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

int
main(int argc, char ** argv) {
    char * input;
    char * output;
    int    i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(1);
    }

    input  = malloc(strlen(argv[1]));
    output = malloc(strlen(argv[1]));

    for (i = 0; i <= strlen(argv[1]); i++) {
        input[i] = argv[1][i];
    }

    output = strdup(input);

    free(input);
    free(output);

    return 0;
}


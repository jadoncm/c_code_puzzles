/* what can go wrong with this code, and what precautions must be taken to use? */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int alloc_re(char **data, unsigned int data_len, unsigned int new_data_len) {
    char *new_data;

    if (!(new_data = malloc(new_data_len))) {
	return -1;
    }

    memcpy(new_data, *data, data_len);

    free(*data);

    *data = new_data;

    return 0;
}

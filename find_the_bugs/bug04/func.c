#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

#include "func.h"

struct data *init_data(const char *key, int val) {
    struct data *data;

    if (!(data = malloc(sizeof *data))) {
        printf("Out of memory!\n");
        return NULL;
    }

    data->key = strdup(key);
    data->val = val;

    return data;
}

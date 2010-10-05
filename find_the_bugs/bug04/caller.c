#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

#include "func.h"

int main(int argc, char **argv) {
    struct data *data;

    if (!(data = (struct data *)init_data("key", 100))) {
        printf("error: %s\n", strerror(errno));
        exit(1);
    }

    printf("%s = %d\n", data->key, data->val);
    return 0;
}


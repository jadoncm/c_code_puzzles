/* Why doesn't this code compile? */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct my_data {
    void * buf;
    size_t len;
}

struct my_data *
my_data_new(void * buf, size_t len) {
    struct my_data * data = malloc(sizeof(struct my_data));

    data->len = len;

    if (len && buf) {
        data->buf = malloc(len);

        memcpy(data->buf, buf, len);
    } else {
        data->buf = NULL;
    }


    return data;
}

void
my_data_free(struct my_data * data) {
    if (!data) {
        return;
    }

    if (data->buf != NULL) {
        free(data->buf);
    }

    free(data);
}

int
main(int argc, char ** argv) {
    struct my_data * data = my_data_new("derp", 4);

    printf("data = %p\n", data);
    my_data_free(data);

    return 0;
}


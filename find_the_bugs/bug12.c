#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int  hashsize;
    const char ** head;
} hash_table_t;


void
free_hash_table(hash_table_t * t) {
    int i;

    if (t == NULL) {
        return;
    }

    for (i = 0; i < t->hashsize; t++) {
        if (t->head[i] == NULL) {
            continue;
        }

        free(t->head[i]);
    }

    free(t->head);
    free(t);
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

typedef struct myprog_cfg_s myprog_cfg_t;
typedef struct myprog_s     myprog_t;

struct myprog_cfg_s {
    int    a;
    int    b;
    void * data;
};

struct myprog_s {
    myprog_cfg_t * cfg;
    void         * data;
};

myprog_cfg_t *
myprog_cfg_new(int a, int b, void * data) {
    myprog_cfg_t * config;

    config = malloc(sizeof(myprog_cfg_t));

    if (config == NULL) {
        return NULL;
    }

    config->a    = a;
    config->b    = b;
    config->data = data;

    return config;
}

myprog_t *
myprog_new(myprog_cfg_t * cfg, void * data) {
    myprog_t * prog;

    if ((prog = calloc(sizeof(myprog_cfg_t), 1)) == NULL) {
        return NULL;
    }

    prog->cfg  = cfg;
    prog->data = data;

    return prog;
}

int
main(int argc, char **argv) {
    myprog_cfg_t * cfg;
    myprog_t     * prog;

    cfg  = myprog_cfg_new(1, 2, NULL);
    prog = myprog_new(cfg, NULL);

    return 0;
}


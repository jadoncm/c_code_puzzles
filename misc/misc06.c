#include <stdio.h>
#include <stdlib.h>

struct hdr_s {
    unsigned char  a;
    unsigned char  b;
    unsigned short c;
    char           data[0];
};

struct data_s {
    int d1;
    int d2;
    int d3;
};

int
main(int argc, char ** argv) {
    char          * buf;
    struct hdr_s  * hdr;
    struct data_s * data;
    struct hdr_s  * hdr_ptr;
    struct data_s * data_ptr;

    buf      = malloc(sizeof(struct hdr_s) + sizeof(struct data_s));
    hdr      = (struct hdr_s *)buf;
    data     = (struct data_s *)hdr->data;

    hdr->a   = 1;
    hdr->b   = 2;
    hdr->c   = 3;

    data->d1 = 4;
    data->d2 = 5;
    data->d3 = 6;

    hdr_ptr  = hdr;
    data_ptr = (struct data_s *)(hdr_ptr + 1);

    return 0;
} /* main */


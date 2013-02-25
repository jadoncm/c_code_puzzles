/*
 * using virtual tables in C is a good way to abstract like-functionality into
 * one basic structure. For example a logging API is well suited for a vtable,
 * there are a set of unified functions like "open", "write", and "close".
 *
 * Instead of having a per-type structure / functions, you will often see the
 * use of vtables. You construct a specific object which returns a parent. The
 * parent structure can then be passed transparently to various functions.
 *
 * The object data vtable always starts with the size of the underlying object,
 * then calls parent_new() to allocate the abstracted parent. You can then cast
 * your specific object data from the parent structure.
 *
 * The memory layout should be something along the lines of:
 *
 * [struct parent][struct my_obj]
 *
 * when a parent_open() is called, it will call my_obj_open(), this will cast
 * the struct parent to the underlying object.
 *
 * but in this code, there is a small bug in the initialization of the parent
 * object. Can you find it?
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

struct parent;
struct vtbl;

struct vtbl {
    size_t size;
    void   (* _open)(struct parent *);
    void   (* _close)(struct parent *);
};

struct parent {
    struct vtbl * vtbl;
    char        * foo;
    int           bar;
};

static struct parent *
parent_new(struct vtbl * vtbl, const char * foo, int bar) {
    struct parent * p;

    p       = calloc(sizeof(struct parent), 1);

    p->foo  = foo ? strdup(foo) : NULL;
    p->bar  = bar;
    p->vtbl = vtbl;

    return p;
}

void
parent_open(struct parent * p) {
    if (p->vtbl->_open) {
        (p->vtbl->_open)(p);
    }
}

void
parent_close(struct parent * p) {
    if (p->vtbl->_close) {
        (p->vtbl->_close)(p);
    }

    free(p->foo);
    free(p);
}

struct my_obj {
    struct parent parent;
    char        * my_obj_data;
};

static void
my_obj_open(struct parent * p) {
    struct my_obj * obj;

    obj = (struct my_obj *)p;

    printf("Opening: %s\n", obj->my_obj_data ? obj->my_obj_data : "derp");
}

static void
my_obj_close(struct parent * p) {
    struct my_obj * obj;

    obj = (struct my_obj *)p;

    printf("Closing: %s\n", obj->my_obj_data ? obj->my_obj_data : "derp");

    free(obj->my_obj_data);
}

static struct vtbl my_obj_vtbl = {
    sizeof(struct my_obj),
    my_obj_open,
    my_obj_close
};

struct parent *
my_obj_new(const char * foo, int bar, const char * my_data) {
    struct parent * parent;
    struct my_obj * obj;

    parent           = parent_new(&my_obj_vtbl, foo, bar);

    obj              = (struct my_obj *)parent;
    obj->my_obj_data = my_data ? strdup(my_data) : NULL;

    return parent;
}

int
main(int argc, char **argv) {
    struct parent * obj;

    obj = my_obj_new("foo", 1024, "bar");

    parent_open(obj);
    parent_close(obj);

    return 0;
}


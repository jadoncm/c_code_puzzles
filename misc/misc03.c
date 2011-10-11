/* what does this code print? Assume c98 or higher. */
#include <stdio.h>

void
print_number(void) {
    static int a;

    ++a;

    printf("%d\n", a);
}

int
main(int argc, char ** argv) {
    print_number();
    print_number();
    print_number();

    return 0;
}


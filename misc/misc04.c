/* what does this program print (of course, knowing the exact memory addresses
 * is not expected, instead use an abstract explanation).
 *
 * Tip 1: it's not as simple as you would think.
 * Tip 2: think C9x standards. Different compilers may generate different code, but
 *       the code is still prone to undefined behaviour.
 * Tip 4: Here is what gcc generates on x64:
 *        leaq	-32(%rbp), %rdx
 *        leaq	-32(%rbp), %rcx
 *        movq	%rcx, %rsi
 *        movq	%rax, %rdi
 *        movl	$0, %eax
 *        call	printf
 * Tip 5: Focus on the load effective address instructions.
 *
 */
#include <stdio.h>

int
main(int argc, char ** argv) {
    char var[20];

    printf("%p %p\n", var, &var);

    return 0;
}


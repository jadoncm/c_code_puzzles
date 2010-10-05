gcc -c -o func.o func.c 2>/dev/null
gcc caller.c -o caller func.o 2>/dev/null

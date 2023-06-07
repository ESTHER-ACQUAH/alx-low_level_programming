#include <unistd.h>

/**
 * My _putchar.c
 * Recursion
 */

int _putchar(char c)
{
    return write(STDOUT_FILENO, &c,1);
}    

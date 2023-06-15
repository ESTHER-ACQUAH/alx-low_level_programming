#include <stdlib.h>
#include "main.h"
/**
 * malloc_checked -  Entry point
 *@b: unsigned int
 * Return: Always 0.
 */
void *malloc_checked(unsigned int b)
{
void *p = malloc(b);
if (p == NULL)
{
exit(98);
}
return (p);
}


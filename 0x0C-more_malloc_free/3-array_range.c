#include <stdlib.h>

/**
 * array_range -  Entry point
 *@min: int
 *@max: int
 * Return: Always 0.
 */
int *array_range(int min, int max)
{
int *ptr;
int size;
int i;

if (min > max)
return (NULL);
size = max - min + 1;
ptr = malloc(size *sizeof(int));
if (ptr == NULL)
return (NULL);
for (i = 0; i < size; i++)
ptr[i] = min + i;
return (ptr);
}


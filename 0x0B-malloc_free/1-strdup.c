#include <stdlib.h>
#include <string.h>

/**
 * _strdup -  duplicate a string
 *@str: the string to duplicate
 * Return: the string duplicated
 */
char *_strdup(char *str)
{
int size;
char *copy;

if (str == NULL)
{
return (NULL);
}

size = strlen(str) + 1;

copy = malloc(size *sizeof(char));
if (copy == NULL)
{
return (NULL);
}

strcpy(copy, str);

return (copy);
}


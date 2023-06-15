. #include <stdlib.h>
#include <string.h>
/**
 * string_nconcat -  Entry point
 *@s1: string
 *@s2: string
 *@n: int
 * Return: Always 0.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
char *result;
unsigned int length1 = strlen(s1);
unsigned int length2 = strlen(s2);
unsigned int i;

if (s2 == NULL)
length2 = 0;
if (n > length2)
n = length2;

result = malloc(length1 + n + 1);

if (result == NULL)
return (NULL);

for (i = 0; i < length1; i++)
result[i] = s1[i];

for (i = 0; i < n; i++)
result[length1 + i] = s2[i];
result[length1 + n] = '\0';
return (result);
}


#include "main.h"

/**
 * factorial - returns the factorial of a number
 * @n: number to return the factorial from
 *
 * Return: factorial of n
 */
int factorial(int n)
{
int  result;

if (n < 0)
{
return (-1);
}
else if (n == 0)
{
return (1);
}
else
{
result = n * factorial(n - 1);
return (result);
}
}


#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - Entry point
 * Desc: Entry
 *@n: int value
 * Return: Always 0 (Success)
 */
int sum_them_all(const unsigned int n, ...)
{
int sum = 0;
va_list arg_list;
unsigned int i;
va_start(arg_list, n);
if (n == 0)
return (0);
for (i = 0; i < n ; i++)
sum += va_arg(arg_list, int);
va_end(arg_list);
return (sum);
}

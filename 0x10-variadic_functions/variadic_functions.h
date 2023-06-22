#ifndef VARIADIC_H
#define VARIADIC_H

int _putchar(char c);
int sum_them_all(const unsigned int n, ...);
/* sum of all its parameters.*/
void print_numbers(const char *separator, const unsigned int n, ...);
/*numbers followed by a new line.*/
void print_strings(const char *separator, const unsigned int n, ...);
/* strings followed by a new line.*/
void print_all(const char * const format, ...);
/*prints anything.*/

#endif

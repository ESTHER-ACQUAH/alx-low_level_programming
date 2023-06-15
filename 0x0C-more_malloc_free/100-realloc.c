#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
/**
 * _realloc -  Entry point
 * @ptr: pointer to the memory previusly
 * @old_size: old size
 * @new_size: new size
 * Return: Always 0.
 */


void* _realloc(void* ptr, unsigned int old_size, unsigned int new_size) 
{
if (new_size == 0) 
{
free(ptr);
return (NULL);
}
if (ptr == NULL) 
{
return (malloc(new_size));
}
if (new_size == old_size) 
{
return (ptr);
}
if (new_ptr != NULL) 
{
unsigned int copy_size = old_size < new_size ? old_size : new_size;
memcpy(new_ptr, ptr, copy_size);
}
free(ptr);
return (new_ptr);
}

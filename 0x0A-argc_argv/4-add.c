#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>

/**
 * main -  prints the sum args positive numbers
 *@argc: argument count 
 *@argv: argument vector
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
    int sum = 0;
    int i;
    if (argc == 1) {
        printf("%d\n", 0);
        return 0;
    }
    else 
    {
        for (i = 1; i < argc; i++) 
	{
            int j = 0;
            while (argv[i][j] != '\0') 
	    {
                if ((argv[i][j]) == 0) 
		{
                    printf("Error\n");
                    return 1;
                }
                j++;
            }
            sum += atoi(argv[i]);
        }
    }
    printf("%d\n", sum);
    return 0;
}


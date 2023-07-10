#include "main.h"
#include <stdlib.h>
#include <stdio.h>  
#include <unistd.h> 
#include <fcntl.h>  

char *create_buffer(void);
void close_file(int fd);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(void)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL) 
	{
		perror("Error allocating buffer");
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int result;

	result = (close(fd));

	if (result == -1) 
	{
		perror("Error closing file descriptor");
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3) 
	{
		fprintf(stderr, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer();
	from = open(argv[1], O_RDONLY);
	if (from == -1) 
	{
		perror("Error opening source file");
		free(buffer);
		exit(98);
	}

	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to == -1) 
	{
		perror("Error opening destination file");
		free(buffer);
		exit(99);
	}

	while ((r = read(from, buffer, 1024)) > 0) 
	{
		w = write(to, buffer, r);
		if (w == -1) 
		{
			perror("Error writing to destination file");
			free(buffer);
			exit(99);
		}
	}

	if (r == -1) {
		perror("Error reading source file");
		free(buffer);
		exit(98);
	}

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}

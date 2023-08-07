#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * read_textfile - Read a text file and print it to STDOUT.
 * @filename: Name of the text file to be read.
 * @letters: Number of letters to be read.
 * Return: The actual number of bytes read and printed on success, 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buf;
	ssize_t t, w;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		perror("Error opening the file");
		return (0);
	}

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL) {
		perror("Error allocating memory");
		close(fd);
		return (0);
	}

	t = read(fd, buf, letters);
	if (t == -1) {
		perror("Error reading the file");
		free(buf);
		close(fd);
		return (0);
	}

	w = write(STDOUT_FILENO, buf, t);
	if (w == -1) {
		perror("Error writing to STDOUT");
		free(buf);
		close(fd);
		return (0);
	}

	free(buf);
	close(fd);
	return (w);
}


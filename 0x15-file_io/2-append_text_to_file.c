#include "main.h"
#include <stdlib.h>
#include <stdio.h>  
#include <unistd.h> 
#include <fcntl.h>  
#include <string.h> 

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist or the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
		len = strlen(text_content);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1) 
	{
		perror("Error opening the file");
		return (-1);
	}

	w = write(fd, text_content, len);
	if (w == -1) 
	{
		perror("Error writing to the file");
		close(fd);
		return (-1);
	}

	close(fd);

	return (1);
}

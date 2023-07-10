#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * create_file - Creates a new file with the specified content.
 *
 * @filename: The name of the file to create.
 * @text_content: The content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int file_des;
	ssize_t bytes_written;

	if (filename == NULL)
		return (-1);
	file_des = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (file_des == -1)
		return (-1);
	if (text_content != NULL)
	{
	bytes_written = write(file_des, text_content, strlen(text_content));
	if (bytes_written == -1)
	{
		close(file_des);
		return (-1);
	}
	}
	close(file_des);
	return (1);
}

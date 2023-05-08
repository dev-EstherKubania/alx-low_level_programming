#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>
/**
 * append_text_to_file - Appends text at the end of a file
 * @filename: the name of the file to append to
 * @text_content: the text to append
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, new;
	size_t length;

	if (filename == NULL)
		return (-1);
	if (text_content == NULL)
		return (1);
	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
		return (-1);
	length = strlen(text_content);
	new = write(file_descriptor, text_content, length);
	close(file_descriptor);
	if (new == -1 || (size_t)new != length)
		return (-1);
	return (1);
}

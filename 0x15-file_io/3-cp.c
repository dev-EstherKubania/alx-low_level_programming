#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"
#define BUF_SIZE 1024

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success.
 *
 * If the number of arguments is not correct, print an error message
 * and exits with status code 97.
 * If file_from does not exist, or if the program is unable to read it,
 * prints an error message and exits with status code 98.
 * If the program is unable to create or write to file_to, it prints an error
 * message and exits with status code 99.
 * If the program is unable to close the file descriptors, it prints an error
 * message and exits with status code 100.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, bytes_read, bytes_written;
	char buf[BUF_SIZE];

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_to == -1)
	{
		fprintf(stderr, "Error: Can't write to file %s\n", argv[2]);
		exit(99);
	}
	while ((bytes_read = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buf, bytes_read);
		if (bytes_written != bytes_read)
	{
			fprintf(stderr, "Error: Can't write to file %s\n", argv[2]);
			exit(99);
	}
	}
	if (bytes_read == -1)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		fprintf(stderr, "Error: Can't close file descriptor\n");
		exit(100);
	}
	return (0);
}


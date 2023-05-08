#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"
#define BUF_SIZE 1024

int copy_file(char *file_from, char *file_to);
void print_usage(char *program_name);
int main(int argc, char *argv[]);

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		print_usage(argv[0]);
	}
	return (copy_file(argv[1], argv[2]));
	return (0);
}

/**
 * print_usage - prints usage message and exits with code 97
 * @program_name: the name of the program
 * Return: none
 */
void print_usage(char *program_name)
{
	dprintf(STDERR_FILENO, "Usage: cp %s file_from file_to\n", program_name);
	exit(97);
}

/**
 * copy_file - copies contents of one file to another file
 * @file_from: the name of the source file
 * @file_to: the name of the destination file
 * Return: 0 on success, or exit with the appropriate error code
 */
int copy_file(char *file_from, char *file_to)
{
	int fd_from, fd_to, bytes_read, bytes_written, close_status;
	char buffer[BUF_SIZE];
	
	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", file_to);
		exit(99);
	}
	while ((bytes_read = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", file_to);
			exit(99);
		}
	}
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	close_status = close(fd_from);
	if (close_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	close_status = close(fd_to);
	if (close_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
	return (0);
}


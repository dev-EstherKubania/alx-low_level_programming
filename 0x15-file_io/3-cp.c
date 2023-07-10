#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * check100 - checks for the correct number of arguments
 * @argc: number of arguments
 *
 * Return: void
 */
void check100(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * check200 - checks that file_from exists and can be read
 * @checked: checks if true of false
 * @file: file_from name
 * @fd_from: file descriptor of file_from, or -1
 * @fd_to: file descriptor of file_to, or -1
 *
 * Return: void
 */
void check200(ssize_t checked, char *file, int fd_from, int fd_to)
{
	if (checked == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		if (fd_from != -1)
			close(fd_from);
		if (fd_to != -1)
			close(fd_to);
		exit(98);
	}
}

/**
 * check300 - checks that file_to was created and/or can be written to
 * @checked: checks if true of false
 * @file: file_to name
 * @fd_from: file descriptor of file_from, or -1
 * @fd_to: file descriptor of file_to, or -1
 *
 * Return: void
 */
void check300(ssize_t checked, char *file, int fd_from, int fd_to)
{
	if (checked == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		if (fd_from != -1)
			close(fd_from);
		if (fd_to != -1)
			close(fd_to);
		exit(99);
	}
}

/**
 * check400 - checks that file descriptors were closed properly
 * @checked: checks if true or false
 * @fd: file descriptor
 *
 * Return: void
 */
void check400(int checked, int fd)
{
	if (checked == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
/**
 * main - copies the content of a file to another file.
 * @argc: number of arguments passed
 * @argv: array of pointers to the arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, close_to, close_from;
	ssize_t lena, lenb;
	char buffer[1024];
	mode_t file_perm;

	check100(argc);
	fd_from = open(argv[1], O_RDONLY);
	check200((ssize_t)fd_from, argv[1], -1, -1);
	file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
	check300((ssize_t)fd_to, argv[2], fd_from, -1);
	lena= 1024;
	while (lena == 1024)
	{
		lena = read(fd_from, buffer, 1024);
		check200(lena, argv[1], fd_from, fd_to);
		lenb = write(fd_to, buffer, lena);
		if (lenb != lena)
			lenb = -1;
		check300(lenb, argv[2], fd_from, fd_to);
	}
	close_to = close(fd_to);
	close_from = close(fd_from);
	check400(close_to, fd_to);
	check400(close_from, fd_from);
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - performs simple operations
 * @argc: number of arguments passed
 * @argv: array of pointers to arguments
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	int a, b, c;
	int (*res)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	a = atoi(argv[1]);
	b = atoi(argv[3]);
	res = get_op_func(argv[2]);
	if (res == NULL)
	{
		printf("Error\n");
		exit(99);
	}
	c = res(a, b);
	printf("%d\n", c);
	return (0);
}

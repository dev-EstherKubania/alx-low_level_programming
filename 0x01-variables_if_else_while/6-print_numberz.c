#include <stdio.h>

/**
 * main - Prints all single digit numbers of base 10 starting from 0,
 *        only using putchar and without char variables.
 *
 * Return: Always 0.
 */
int main(void)
{
	int f;

	for (f = 0; f < 10; f++)
	putchar(f);
	putchar('\n');
	return (0);
}

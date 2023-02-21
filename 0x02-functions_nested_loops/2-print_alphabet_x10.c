#include "main.h"
/**
 * print_alphabet_x10 - prints 10 times the alphabet
 *
 * Return: void
 */
void print_alphabet_x10(void)
{
	int c = 0;
	char lower;

	while (c++ <= 9)
	{
		for (lower = 'a'; lower <= 'z'; lower++)
		_putchar(lower);
		_putchar(10);
	}
}

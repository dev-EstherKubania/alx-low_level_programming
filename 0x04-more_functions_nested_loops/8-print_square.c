#include "main.h"

/**
 * print_square - a function that prints a square, followed by a new line
 * @size: size of width and length
 * Return: a square made of '#'
 */
void print_square(int size)
{
	int w, l;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (w = 1; w <= size; w++)
		{
			_putchar('#');
			for (l = 2; l <= size; l++)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
}

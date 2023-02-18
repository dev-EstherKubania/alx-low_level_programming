#include <stdio.h>

/**
 * main - prints all possible combinations of single-digit
 *	numbers.
 * 01 and 10 are considered the same combination of the two
 * digits 0 and 1.
 * Print only the smallest combination of two digits.
 * Return: Always 0.
 */
int main(void)
{
	int a, b;

	for (a = '0'; a < '9'; a++)
	{
	for (b = a + 1; b <= '9'; b++)
	{
	if (b != a)
	{
	putchar(a);
	putchar(b);
	if (a == '8' && b == '9')
	continue;
	putchar(',');
	putchar(' ');
	}
	}
	}
	putchar('\n');
	return (0);
}


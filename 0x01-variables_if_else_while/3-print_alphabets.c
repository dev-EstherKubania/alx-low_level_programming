#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase, and then in uppercase.
 *
 * Return: Always 0.
 */
int main(void)
{
	char ch;

	/* print lowercase letters */
	for (ch = 'a'; ch <= 'z'; ch++)
	putchar(ch);

	/* print uppercase letters */
	for (ch = 'A'; ch <= 'Z'; ch++)
	putchar(ch);
	putchar('\n');

	return (0);
}

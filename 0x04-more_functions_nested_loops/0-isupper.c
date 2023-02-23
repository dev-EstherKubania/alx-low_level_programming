#include "main.h"

/**
 * _isupper - function checks for uppercase character.
 * @c: c -  Variable
 * Return: Always 0
 */
int _isupper(int c);
{
	if ((c >= 48) && (c <= 57))
	return (1);
	else
	return (0);
}

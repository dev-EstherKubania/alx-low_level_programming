#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a str containing a binary number
 * Return: converted number or 0 if string b is NULL or has characters
 *          that are not 0 or 1
 */
unsigned int binary_to_uint(const char *b)
{
	int j;
	unsigned int decimalnum = 0;

	if (b == NULL)
		return (0);
	for (j = 0; b[j]; j++)
	{
	if (*b != '0' && *b != '1')
		return (0);
	decimalnum = 2 * decimalnum + (b[j] - '0');
	}

	return (decimalnum);
}

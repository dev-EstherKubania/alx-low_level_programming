#include "main.h"

/**
 * flip_bits - returns the number of bits that need to be flipped to
 *             convert one number to another.
 * @n: the first number
 * @m: the second number
 * Return: the number of bits to be flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int the_count = 0;
	unsigned long int different = n ^ m;

	while (different)
	{
	the_count += different & 1;
	different >>= 1;
	}
	return (the_count);
}

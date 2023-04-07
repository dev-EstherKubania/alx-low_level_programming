#include "main.h"

/**
 * set_bit - sets the value of a bit at a given index to 1.
 * @n: pointer to an unsigned long int variable
 * @index: the index of the bit to be set, starting from 0
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (8 * (sizeof(unsigned long int))))
	{
		return (-1);
	}
	*n |= (1UL << index);
		return (1);
}

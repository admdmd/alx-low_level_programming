#include "main.h"

/**
 * clear_bit - resets value of a bit to 0.
 * @n: pointer to unsigned long int.
 * @index: index of a bit.
 *
 * Return: 1 on success ,else -1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int g;

	if (index > 63)
		return (-1);

	m = 1 << index;

	if (*n & g)
		*n ^= g;

	return (1);
}

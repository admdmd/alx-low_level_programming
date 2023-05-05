#include "main.h"

/**
 * set_bit - Sets value of a bit at a given index to 1.
 * @n: pointer to a declared bit
 * @index: The target index
 *
 * Return: 1, or -1 on error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n ^= (1 << index);

	return (1);
}


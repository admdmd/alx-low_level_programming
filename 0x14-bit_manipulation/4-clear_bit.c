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
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n &= ~(1 << index);

	return (1);
}

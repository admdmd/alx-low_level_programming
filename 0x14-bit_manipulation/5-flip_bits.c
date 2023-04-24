#include "main.h"

/**
 * flip_bits - num of bits to flip
 * @n: number to be moved
 * @m: destination number
 *
 * Return: number of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int numby;

	for (numby = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			numby++;
	}

	return (numby);
}

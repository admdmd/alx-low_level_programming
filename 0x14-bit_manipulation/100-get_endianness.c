#include "main.h"

/**
 * get_endianness - gets level of endianness
 *
 * Return: 0 for large endian, 1 for little endian
 */
int get_endianness(void)
{
	unsigned int e;
	char *f;

	x = 1;
	f = (char *) &e;

	return ((int)*f);
}

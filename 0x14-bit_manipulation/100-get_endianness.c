#include "main.h"

/**
 * get_endianness - gets level of endianness
 *
 * Return: 0 for large endian, 1 for little endian
 */
int get_endianness(void)
{
	int x = 1;
	char *e = (char *)&x;

	if (*e == 1)
		return (1);

	return (0);
}

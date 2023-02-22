#include "main.h"

/**
 * _isalpha - if a character is lowercase or uppercase
 * @c: the character
 * Return: 1 if c is lowercase or uppercase , if not 0
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

#include <stdio.h>
/**
 * main - prints the size of various types on the computer
 * it is compiled and run on
 * * Return: 0 (success)
 */
int main(void)
{
	printf("size of a char: %zu 1 byte(s)\n", sizeof(char));
	printf("size of an int: %zu 4 byte(s)\n", sizeof(int));
	printf("size of a long int: %zu 4 byte(s)\n", sizeof(long int));
	printf("size of a long long int: %zu 8 byte(s)\n", sizeof(long long int));
	printf("size of a float: %zu 4 byte(s)\n", sizeof(float));
	return (0);
}

#include "main.h"

/**
 * expandable - checks if files can be opened.
 * @file_from: sending file
 * @file_to: recieving file
 * @argv: arguments vector
 * Return: 0 on success
 */
int expandable(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	return (0);
}

/**
 * main - program that copies the content of a file to another file
 * @ac: counts number of arguments
 * @av: arguments vector.
 * Return: Always 0.
 */
int main(int ac, char *av[])
{
	int file_from, file_to, man_file;
	ssize_t y, z;
	char buffer[1024];

	if (ac < 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open(av[1], O_RDONLY);
	file_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	expandable(file_from, file_to, av);

	y = 1024;
	while (y == 1024)
	{
		y = read(file_from, buffer, 1024);
		if (y == -1)
			expandable(-1, 0, av);
		z = write(file_to, buffer, y);
		if (z == -1)
			expandable(0, -1, av);
	}

	man_file = close(file_from);
	if (man_file == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	man_file = close(file_to);
	if (man_file == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	return (0);
}

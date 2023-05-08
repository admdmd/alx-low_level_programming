#include <stdio.h>
#include "main.h"

/**
 * read_textfile - reads and prints the letters of a stream
 * @filename: stream filename
 * @letters: number of printed letters.
 * Return: numbers of letters printed, 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int i;
	ssize_t xrd;
	ssize_t xwr;
	char *buffer;

	if (filename == NULL)
		return (0);

	i = open(filename, O_RDONLY);

	if (i == -1)
		return (0);

	buffer = malloc(sizeof(char) * (letters));

	if (buffer == NULL)
		return (0);

	xrd = read(i, buffer, letters);
	xwr = write(STDOUT_FILENO, buffer, xrd);

	close(i);

	free(buffer);

	return (xwr);
}

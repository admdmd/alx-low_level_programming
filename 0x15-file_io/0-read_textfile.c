#include "main.h"

/**
 * read_textfile - reads text file and prints the letters
 * @filename: filiename.
 * @letters: numbers of letters printed.
 *
 * Return: numbers of letters printed, returns 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int xd;
	ssize_t nd, nr;
	char *buf;

	if (!filename)
		return (0);

	xd = open(filename, O_RDONLY);

	if (xd == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	nd = read(xd, buf, letters);
	nr = write(STDOUT_FILENO, buf, nd);

	close(xd);

	free(buf);

	return (nr);
}

#include "main.h"

/**
 * create_file - creates a file
 * @filename: name of file
 * @text_content: content written in the file.
 *
 * Return: 1 on succes, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int n;
	int rw;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (n = 0; text_content[n]; n++)
		;

	rw = write(fd, text_content, n);

	if (rw == -1)
		return (-1);

	close(fd);

	return (1);
}

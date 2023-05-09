#include "main.h"

/**
 * create_file - objective
 * @filename: Name of target file
 * @text_content: content to write to the file
 *
 * Return: 1 on success and -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int y;
	int z;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	if (text_content == NULL)
		text_content = "";

	for (y = 0; text_content[y]; y++)
		;

	z = write(fd, text_content, y);

	if (z == -1)
		return (-1);

	close(fd);

	return (1);
}

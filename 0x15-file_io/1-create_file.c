#include "main.h"
#include <stdio.h>

/**
 * create_file - creates a file
 * @filename: filename
 * @text_content: content writed in the file
 *
 * Return: 1 if it success. -1 if it fails
 */
int create_file(const char *filename, char *text_content)
{
	int ff;
	int xx;
	int ww;

	if (!filename)
		return (-1);

	ff = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (ff == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (xx = 0; text_content[xx]; xx++)
		;

	ww = write(ff, text_content, xx);

	if (ww == -1)
		return (-1);

	close(ff);

	return (1);
}

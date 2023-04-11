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
	int ff = 0;
	int xx = 0;
	int len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	ff = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	xx = write(ff, text_content, len);

	if (ff == -1 || xx == -1)
		return (-1);

	close(ff);
	return (-1);
}

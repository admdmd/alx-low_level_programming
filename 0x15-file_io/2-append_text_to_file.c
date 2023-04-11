#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: filename.
 * @text_content: added content.
 *
 * Return: 1 if the file exists. -1 if the fails does not exist
 * or if it fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int ff;
	int xx;
	int ww;

	if (!filename)
		return (-1);

	ff = open(filename, O_WRONLY | O_APPEND);

	if (ff == -1)
		return (-1);

	if (text_content)
	{
		for (xx = 0; text_content[xx]; xx++)
			;

		ww = write(ff, text_content, xx);

		if (ww == -1)
			return (-1);
	}

	close(ff);

	return (1);
}

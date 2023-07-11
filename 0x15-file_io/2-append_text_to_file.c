#include "main.h"

/**
 * append_text_to_file - appends text to a file
 * @filename: filename.
 * @text_content: added content.
 *
 * Return: 1 if file exists,else -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fx;
	int n;
	int rw;
	
	if (!filename)
		return (-1);

	fx = open(filename, O_WRONLY | O_APPEND);

	if (fx == -1)
		return (-1);

	if (text_content)
	{
		for (n = 0; text_content[n]; n++)
			;

		rw = write(fx, text_content, n);

		if (rw == -1)
			return (-1);
	}

	close(fx);

	return (1);
}

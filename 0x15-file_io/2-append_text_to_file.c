#include "main.h"

/**
 * append_text_to_file - appends text to the end of a file
 * @filename: name of file.
 * @text_content: text ro be added.
 *
 * Return: 1 on successful operation,-1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
int fd;
int y;
int z;

if (filename == NULL)
return (-1);

fd = open(filename, O_WRONLY | O_APPEND);

if (fd == -1)
return (-1);

if (text_content != NULL)
{
for (y = 0; text_content[y]; y++)
	;
z = write(fd, text_content, y);

if (z == -1)
return (-1);
}
close(fd);
return (1);
}

#include "main.h"
#include <stdio.h>

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: filename
 * @letters: numbers of letters printed
 *
 * Return: numbers of letters printed. It fails, returns 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
ssize_t xx;
ssize_t ff;
ssize_t tt;
char *abc;

ff = open(filename, O_RDONLY);
if (ff == -1)
return (0);
abc = malloc(sizeof(char) * letters);
tt = read(ff, abc, letters);
xx = write(STDOUT_FILENO, abc, tt);

free(abc);
close(ff);
return (xx);
}

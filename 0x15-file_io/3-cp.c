#include "main.h"
#include <stdio.h>

void copy_file(int file_from, int file_to);

/**
 * main - program that copies the content of a file to another file
 * @argc: counts arguments
 * @argv: counts arguemnt vector.
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
int file_from, file_to;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

file_from = open(argv[1], O_RDONLY);
if (file_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file_from\n");
exit(98);
}

file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
if (file_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to file_to\n");
exit(99);
}

copy_file(file_from, file_to);

close(file_from);
if (file_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
exit(100);
}

close(file_to);
if (file_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
exit(100);
}

return (0);
}

/**
 * copy_file - copies the content of a file to another file
 * @file_from: source file descriptor
 * @file_to: destination file descriptor
 */
void copy_file(int file_from, int file_to)
{
ssize_t nchar, nwr;
char buffer[1024];

nchar = 1024;

while (nchar == 1024)
{
nchar = read(file_from, buffer, 1024);
if (nchar == -1)
{
perror("Error: Can't read from file");
exit(98);
}
nwr = write(file_to, buffer, nchar);
if (nwr == -1)
{
perror("Error: Can't read from file");
exit(99);
}
}
}


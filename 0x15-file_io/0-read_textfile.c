#include "main.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * read_textfile - Reads text file and prints it to POSIX std output.
 * @filename: File name pointer
 * @letters: Number of letters to be read and printed
 * Return: 0 If fail or if filename is NULL
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t op, re, wr;
	char *buff;

	if (filename == NULL)
		return (0);

	buff = malloc(sizeof(char) * letters);
	if (buff ==  NULL)
		return (0);

	op = open(filename, O_RDONLY);
	re = read(op, buff, letters);
	wr = write(STDOUT_FILENO, buff, re);

	if (op == -1 || re == -1 || wr == -1 || wr != re)
	{
		free(buff);
		return (0);
	}

	free(buff);
	close(op);

	return (wr);

}

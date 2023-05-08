#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - reads & prints from a file
 * @filename: path to the file
 * @letters: chars to read
 * Return: chars read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fdr;
	char *buff;
	ssize_t bytes, r;

	if (!filename)
		return (0);
	fdr = open(filename, O_RDONLY);
	if (fdr == -1)
	{
		close(fdr);
		return (0);
	}

	buff = malloc(sizeof(char) * letters);
	if (!buff)
	{
		close(fdr);
		return (0);
	}

	bytes = read(fdr, buff, letters);

	if (bytes == -1)
	{
		close(fdr);
		free(buff);
		return (0);
	}

	r = write(STDOUT_FILENO, buff, bytes);

	if (r == -1)
	{
		close(fdr);
		free(buff);
		return (0);
	}
	close(fdr);
	return (bytes);
}

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

/**
 * create_file - append to the file
 * @filename: path to the file
 * @text_content: content of the file
 * Return: chars read
 */

int create_file(const char *filename, char *text_content)
{
	int fdr;
	ssize_t w;
	int size;
	char *me;

	if (!filename)
	{
		return (-1);
	}
	fdr = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (fdr == -1)
		return (-1);
	if (!text_content)
	{
		close(fdr);
		return (1);
	}
	size = _strlen(text_content);
	me = malloc(sizeof(char) * size);
	if (!me)
	{
		close(fdr);
		return (-1);
	}
	w = write(fdr, text_content, size);
	if (w == -1)
	{
		close(fdr);
		free(me);
		return (-1);
	}
	close(fdr);
	free(me);
	return (1);
}

/**
 * _strlen - len
 *
 * @s: is a pointer to a character
 *
 * Return: Always 0.
 */

int _strlen(const char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}

	return (i);
}

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

/**
 * append_text_to_file - apends text to the file
 * @filename: path to the file
 * @text_content: content of the file
 * Return: 1 or -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fdr;
	ssize_t w;
	int size;

	if (!filename)
		return (-1);

	fdr = open(filename, O_WRONLY | O_APPEND);

	if (fdr == -1)
		return (-1);

	if (!text_content)
	{
		close(fdr);
		return (1);
	}

	size = _strlen(text_content);
	w = write(fdr, text_content, size);

	if (w == -1)
	{
		close(fdr);
		return (-1);
	}
	close(fdr);
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


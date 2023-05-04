#include "main.h"

/**
 * binary_to_uint - converts binary number to unsigned int
 * @b: the binary number
 *
 * Return: unsigned int
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int nb = 0;

	if (!b)
		return (0);
	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);
		nb = nb * 2 + (*b++ - '0');
	}
	return (nb);
}

#include "main.h"

/**
 * get_endianness - returns endianness of system
 *
 * Return: 0 if big endian, and 1 if small
 */


int get_endianness(void)
{
	unsigned long int n = 1;

	return (*(char *)&n);
}

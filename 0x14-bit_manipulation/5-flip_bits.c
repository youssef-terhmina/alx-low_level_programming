#include "main.h"

/**
 * flip_bits - get number of bits needed to be flipped to
 * transform one number to another
 *
 * @n: 1st number
 * @m: 2nd number
 *
 * Return: number of bits to flip to convert numbers
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int val = n ^ m;
	unsigned int cnt = 0;

	while (val)
	{
		if (val & 1ul)
			cnt++;
		val = val >> 1;
	}
	return (cnt);
}

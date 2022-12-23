#include "main.h"

/**
 * reverse_array - function that reverse content of array
 * @a: array
 * @n: number of elements
 */

void reverse_array(int *a, int n)
{
	int i;
	int j;

	for (i = 0; i < n; i++)
	{
		n--;
		j = a[i];
		a[i] = a[n];
		a[n] = j;
	}
}

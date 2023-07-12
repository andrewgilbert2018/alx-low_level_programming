#include "search_algos.h"
#include <math.h>
void special_print(int i, int *array);
int linear_search_ord(int low, int high, int value, int *array);
/**
 *jump_search - search for a value in a list with o(n)
 *@array: array
 *@size: size of the array
 *@value: value to search for
 *Return: index of the value
 */
int jump_search(int *array, size_t size, int value)
{
	int i, m, low, high, found = -1;

	if (!array)
		return (found);
	m = sqrt(size);
	for (i = 0; i < (int)size; i += m)
	{
		low = i - m;
		high = i;
		if (array[high] < value)
		{
			special_print(i, array);
		}
		else if (array[high] >= value)
		{
			printf("Value found between indexes [%d] and [%d]\n", low, high);
			found = linear_search_ord(low, high, value, array);
			return (found);
		}
	}
	printf("Value found between indexes [%d] and [%d]\n", high, i);
	found = linear_search_ord(high, (int)size - 1, value, array);
	return (found);
}

/**
 *special_print - prints every try to find the value
 *@i: index
 *@array: array to get info from
 *Return - Nothing
 */
void special_print(int i, int *array)
{
	printf("Value checked array[%d] = [%d]\n", i, array[i]);
}

/**
 *linear_search_ord - linear search for small parts
 *@low: low part
 *@high: end of list
 *@value: value to search
 *@array: list to search in
 *Return: index of value found or -1 if not found
 */
int linear_search_ord(int low, int high, int value, int *array)
{
	int found = -1, i;

	for (i = low; i <= high; i++)
	{
		special_print(i, array);
		if (array[i] == value)
		{
			return (i);
		}
	}
	return (found);
}

#include "search_algos.h"
void special_print(int i, int *array);
/**
 *linear_search - search for a value in a list with o(n)
 *@array: array
 *@size: size of the array
 *@value: value to search for
 *Return: index of the value
 */
int linear_search(int *array, size_t size, int value)
{
	int i, found = -1;

	if (!array)
		return (found);
	for (i = 0; i < (int)size; i++)
	{
		special_print(i, array);
		if (array[i] == value)
		{
			found = i;
			break;
		}
	}
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

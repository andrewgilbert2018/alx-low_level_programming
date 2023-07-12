#include "search_algos.h"
void special_print(int low, int high, int *array);
int recursive_binary(int low, int high, int value, int *list);
/**
 *binary_search - search for a value in a list with o(logn)
 *@array: array
 *@size: size of the array
 *@value: value to search for
 *Return: index of the value
 */
int binary_search(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (recursive_binary(0, size - 1, value, array));
}


/**
 *recursive_binary - search by half
 *@low: starting point
 *@high: end point
 *@value: searched_value
 *@list: array list
 *Return: Nothing
 */
int recursive_binary(int low, int high, int value, int *list)
{
	int pivote = low + (high - low) / 2;

	special_print(low, high, list);
	if (low == high && value != list[pivote])
		return (-1);
	else if (value > list[pivote])
	{
		pivote = recursive_binary(pivote + 1, high, value, list);
	}
	else if (value < list[pivote])
	{
		pivote = recursive_binary(low, pivote - 1, value, list);
	}
	return (pivote);
}


/**
 *special_print - prints every try to find the value
 *@low: starting point
 *@high: end point
 *@array: array list
 *Return: Nothing
 */
void special_print(int low, int high, int *array)
{
	int i = 0;

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		if (i != high)
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
	}
}

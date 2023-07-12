#include "search_algos.h"
void special_print(int pivote, int *array, int size);
int recursive_binary(int low, int high, int value, int *list);
/**
 *interpolation_search - search for a value in a list with o(logn)
 *@array: array
 *@size: size of the array
 *@value: value to search for
 *Return: index of the value
 */
int interpolation_search(int *array, size_t size, int value)
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
	size_t pivote;
	double denominator;

	denominator = ((double)(high - low) / (list[high] - list[low]));
	pivote = low + (denominator * (value - list[low]));
	special_print(pivote, list, high);
	if ((low == high && value != list[pivote]) || (int)pivote > high)
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
 *@pivote: middle point
 *@array: list
 *@size: max len of array
 *Return: Nothing
 */
void special_print(int pivote, int *array, int size)
{
	if (pivote <= size)
		printf("Value checked array[%d] = [%d]\n", pivote, array[pivote]);
	else
		printf("Value checked array[%d] is out of range\n", pivote);
}

#include "search_algos.h"
#include <math.h>
void special_print(listint_t *list);
listint_t *linear_search_ord(listint_t *tail, listint_t *head, int value);
/**
 *jump_list - search for a value in a list with o(n)
 *@list: list
 *@size: size of the list
 *@value: value to search for
 *Return: node found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	int i, m;
	listint_t *head = NULL, *tail = NULL;
	char question[] = "Value found between indexes [%d] and [%d]\n";

	if (!list)
		return (NULL);
	head = tail = list;
	m = sqrt(size);
	for (i = 1; head->next != NULL; i++)
	{
		if ((int)head->index > 0 && (int)head->index % m == 0)
		{
			special_print(head);
			if ((int)head->next->n > value)
			{
				printf(question, (int)tail->index, (int)head->index);
				return (linear_search_ord(tail, head, value));
			}
		tail = head;
		}
		head = head->next;
	}
	special_print(head);
	printf(question, (int)tail->index, (int)head->index);
	return (linear_search_ord(tail, head, value));
}

/**
 *special_print - prints every try to find the value
 *@list: list to get info from
 *Return - Nothing
 */
void special_print(listint_t *list)
{
	char question[] = "Value checked at index [%d] = [%d]\n";

	printf(question, (int)list->index, (int)list->n);
}

/**
 *linear_search_ord - linear search for small parts
 *@tail: low part
 *@head: end of list
 *@value: value to search
 *Return: index of value found or -1 if not found
 */
listint_t *linear_search_ord(listint_t *tail, listint_t *head, int value)
{
	int i;

	for (i = 0; tail != NULL && head != NULL && tail->index <= head->index; i++)
	{
		special_print(tail);
		if (tail->n == value)
			return (tail);
		tail = tail->next;
	}
	return (NULL);
}

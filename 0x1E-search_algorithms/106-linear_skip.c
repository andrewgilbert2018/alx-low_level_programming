#include "search_algos.h"
#include <math.h>
void special_print(skiplist_t *list);
skiplist_t *linear_search_ord(skiplist_t *tail, skiplist_t *head, int value);
/**
 *linear_skip - search for a value in a list with o(n*m)
 *@list: list
 *@value: value to search for
 *Return: node found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	int i;
	skiplist_t *head = NULL, *tail = NULL;
	char question[] = "Value found between indexes [%d] and [%d]\n";

	if (!list)
		return (NULL);
	head = tail = list;
	for (i = 1; head->express != NULL; i++)
	{
		tail = head;
		head = head->express;
		special_print(head);
		if ((int)head->next->n > value)
		{
			printf(question, (int)tail->index, (int)head->index);
			return (linear_search_ord(tail, head, value));
		}
	}
	tail = head;
	while (head->next != NULL)
		head = head->next;
	printf(question, (int)tail->index, (int)head->index);
	return (linear_search_ord(tail, head, value));
}

/**
 *special_print - prints every try to find the value
 *@list: list to get info from
 *Return - Nothing
 */
void special_print(skiplist_t *list)
{
	char question[] = "Value checked at index [%d] = [%d]\n";

	if (!list)
		return;
	printf(question, (int)list->index, (int)list->n);
}

/**
 *linear_search_ord - linear search for small parts
 *@tail: low part
 *@head: end of list
 *@value: value to search
 *Return: index of value found or -1 if not found
 */
skiplist_t *linear_search_ord(skiplist_t *tail, skiplist_t *head, int value)
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

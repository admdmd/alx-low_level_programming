#include "lists.h"

/**
 * listint_len - number of items in the array
 * @h: list of items in a string
 *
 * Return: 0
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}

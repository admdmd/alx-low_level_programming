#include "lists.h"

/**
 * print_dlistint - prints the elements of a list
 * dlistint_t list
 * @h: head of the list
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *temp;
	size_t x = 0;

	temp = h;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		x++;
	}
	return (x);
}

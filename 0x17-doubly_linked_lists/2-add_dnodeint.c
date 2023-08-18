#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a doubly linked list
 * @head: double pointer to the list
 * @n: data to insert in the new node
 *
 * Return: the address of the new element, 0 on failure
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newn;

	if (!head)
		return (NULL);

	newn = malloc(sizeof(dlistint_t));
	if (!newn)
		return (NULL);

	newn->n = n;

	newn->next = *head;
	newn->prev = NULL;

	if (*head)
		(*head)->prev = newn;

	*head = newn;

	return (newn);
}

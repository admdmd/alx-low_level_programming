#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list
 * @head: head of a list.
 *
 * Return: the head node's data.
 */
int pop_listint(listint_t **head)
{
	int hnode;
	listint_t *h;
	listint_t *pres;

	if (*head == NULL)
		return (0);

	pres = *head;

	hnode = pres->n;

	h = pres->next;

	free(pres);

	*head = h;

	return (hnode);
}

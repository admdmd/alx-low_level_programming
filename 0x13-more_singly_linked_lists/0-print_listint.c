#include "lists.h"

/**
 * print_listint - print number of nodes
 * @h: pointer to the list
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
size_t nodelen = 0;

if (h != NULL)
{
printf("%d\n", h->n);
h = h->next;
nodelen++;
}
return (nodelen);
}

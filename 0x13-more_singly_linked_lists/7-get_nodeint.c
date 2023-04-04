#include "lists.h"

/**
 * get_nodeint_at_index - func that returns the nth node of a listint_t list
 * @head:  pointer to head node
 * @index: index of the node
 * Return: pointer to indexed node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	size_t num;

	for (num = 0; (num < index) && (head->next); num++)
	head = head->next;

	if (num < index)
	return (NULL);

	return (head);
}

#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 * @head: Pointer to the head of the list.
 * @index: Index of the node to retrieve.
 * Return: Pointer to the nth node, or NULL if not found.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;
	dlistint_t *current_node = head;

	for (i = 0; current_node != NULL && i < index; i++)
		current_node = current_node->next;

	return (current_node);
}


#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given position
 *	in a dlistint_t linked list.
 * @head: Pointer to a pointer to the head node of the list.
 * @index: Index of the node that should be deleted. Index starts at 0.
 * Return: 1 if deletion succeeds, -1 if it fails.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp, *current_node;
	unsigned int i;

	if (head == NULL || *head == NULL)
	{
	return (-1);
	}

	current_node = *head;

	if (index == 0)
	{
	*head = (*head)->next;
	if (*head != NULL)
	{
	(*head)->prev = NULL;
	}
	free(current_node);
	return (1);
	}

	for (i = 0; i < index && current_node != NULL; i++)
	{
	current_node = current_node->next;
	}

	if (current_node == NULL)
	{
	return (-1);
	}

	temp = current_node->prev;
	temp->next = current_node->next;
	if (current_node->next != NULL)
	{
	current_node->next->prev = temp;
	}

	free(current_node);
	return (1);
}


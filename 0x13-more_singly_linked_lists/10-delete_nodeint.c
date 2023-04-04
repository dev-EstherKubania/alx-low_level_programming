#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at index `index`
 *                           of a `listint_t` linked list.
 * @head: Pointer to the head node of the list.
 * @index: Index of the node to delete, starting at 0.
 * Return: 1 if the deletion was successful, -1 otherwise.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tmp, *current = *head;
	unsigned int node;

	if (current == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(current);
		return (1);
	}

	for (node = 0; node < (index - 1); node++)
	{
		if (current->next == NULL)
			return (-1);

		current = current->next;
	}

	tmp = current->next;
	current->next = tmp->next;
	free(tmp);
	return (1);
}

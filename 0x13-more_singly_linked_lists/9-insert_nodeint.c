#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node in a position in a linked list.
 * @head: Pointer to a pointer to the head node of the list.
 * @idx: Index of the list where the new node should be added.
 * @n: The value to be stored in the new node.
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i = 0;
	listint_t *new_node, *current_node;

	if (head == NULL)
		return (NULL);
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	if (idx == 0)
		{
	new_node->next = *head;
	*head = new_node;
		return (new_node);
	}
	current_node = *head;
	while (i < idx - 1 && current_node != NULL)
	{
	current_node = current_node->next;
		i++;
	}
	if (i < idx - 1)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = current_node->next;
	current_node->next = new_node;
	return (new_node);
}

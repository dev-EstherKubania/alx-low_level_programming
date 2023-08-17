#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all data (n) in a dlistint_t linked list.
 * @head: Pointer to the head node of the list.
 * Return: Sum of all data values in the list.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *current_node = head;

	while (current_node != NULL)
	{
	sum += current_node->n;
	current_node = current_node->next;
	}

	return (sum);
}


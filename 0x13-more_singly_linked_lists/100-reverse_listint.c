#include "lists.h"
/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 * Return: pointer to the new first node
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *reversed = NULL;

	while (*head)
	{
	reversed = (*head)->next;
	(*head)->next = prev;
	prev = *head;
	*head = reversed;
	}
	*head = prev;
	return (*head);
}


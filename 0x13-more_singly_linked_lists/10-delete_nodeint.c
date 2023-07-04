#include "lists.h"

/**
* delete_nodeint_at_index - deletes a node in a linked list at a certain index

* @head: pointer to a pointer to the head of the list
* @index: index of the node that should be deleted
*
* Return: 1 if it succeeded, -1 if it failed
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *current = *head, *tmp;
unsigned int i;

if (head == NULL || *head == NULL)
return (-1);

if (index == 0)
{
*head = current->next;
free(current);
return (1);
}

for (i = 0; i < index - 1; i++)
{
if (current->next == NULL)
return (-1);

current = current->next;

}

tmp = current->next;
if (tmp == NULL)
return (-1);

current->next = tmp->next;
free(tmp);

return (1);
}

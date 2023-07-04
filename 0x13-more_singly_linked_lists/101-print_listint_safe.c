#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
* print_listint_safe - Prints a listint_t linked list.
* @head: A pointer to the head of the listint_t list.
*
* Return: The number of nodes in the list.
*/
size_t print_listint_safe(const listint_t *head);
{
const listint_t *tortoise, *hare;

size_t count = 0;

tortoise = head;
hare = head;

while (tortoise != NULL && hare != NULL && hare->next != NULL)
{
printf("[%p]%d\n";, (void *)tortoise, tortoise->n);
count++;

tortoise = tortoise->next;
hare = hare-&gt;next->next;

if (tortoise == hare)
{
printf("[%p]%d\n", (void *)tortoise, tortoise->n);
printf("->[%p]%d\n", (void *)hare, hare->n);
printf("->[%p]%d\n", (void *)tortoise->next, tortoise->next->n);
count++;
break;
}
}

return (count);
}

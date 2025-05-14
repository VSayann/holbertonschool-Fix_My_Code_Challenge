#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
 int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
 {
     dlistint_t *current = *head;
     unsigned int i;
 
     if (!head || !(*head))
         return (-1);
 
     for (i = 0; current && i < index; i++)
         current = current->next;
 
     if (!current)
         return (-1);
 
     if (current->prev)
         current->prev->next = current->next;
     else
         *head = current->next;
 
     if (current->next)
         current->next->prev = current->prev;
 
     free(current);
     return (1);
 }

#include "sort.h"


/**
 * insertion_sort_list - Sort a doubly linked list of integers
 * in ascending  order
 * @list: A doubly linked list of integers
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *node = *list, *temp_next, *p_node, *n_node, *p2_nodes;
	bool go_to_nxt_node = true;

	if ((*list)->next == NULL || *list == NULL)
		return;
	while (node)
	{
		if (go_to_nxt_node)
			temp_next = node->next;
		if (node->prev && node->n < node->prev->n)
		{
			p_node = node->prev;
			n_node = node->next;
			if (node->prev && node->prev->prev)
				p2_nodes = node->prev->prev;
			else
				p2_nodes = NULL;
			node->prev = p2_nodes;
			node->next = p_node;
			if (p2_nodes)
				p2_nodes->next = node;
			p_node->prev = node;
			p_node->next = n_node;
			if (n_node)
				n_node->prev = p_node;
			go_to_nxt_node	 = false;
			if (p2_nodes == NULL)
			{
				*list = node;
				go_to_nxt_node = true;
			}
			print_list(*list);
		}
		else
			go_to_nxt_node = true;
		if (go_to_nxt_node)
			node = temp_next;
	}
}

#include "sort.h"


/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: A doubly linked list
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *node, *n_node, *p_node;
	bool swapped = true;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = *list;
	while (swapped)
	{
		swapped = false;
		while (node->next)
		{
			n_node = node->next;
			p_node = node->prev;
			if (node->n > node->next->n)
			{
				swap_list(node, node->next);
				set_head_list(p_node, n_node, list);
				swapped = true;
				print_list(*list);
			}
			else
				node = n_node;
		}
		if (!swapped)
			break;
		swapped = false;
		while (node->prev)
		{
			p_node = node->prev;
			if (node->n < node->prev->n)
			{
				swap_list(node->prev, node);
				set_head_list(node->prev, node, list);
				swapped = true;
				print_list(*list);
			}
			else
				node = p_node;
		}
	}
}


/**
 * swap_list - swap two nodes of a linked list
 * @first_node: The first node
 * @second_node: The second node
*/
void swap_list(listint_t *first_node, listint_t *second_node)
{
	listint_t *pf_node, *sn_node;

	if (first_node == NULL || second_node == NULL)
		return;

	pf_node = first_node->prev;
	sn_node = second_node->next;
	first_node->prev = second_node;
	second_node->next = first_node;
	if (pf_node)
	{
		pf_node->next = second_node;
		second_node->prev = pf_node;
	}
	else
		second_node->prev = NULL;

	if (sn_node)
	{
		sn_node->prev = first_node;
		first_node->next = sn_node;
	}
	else
		first_node->next = NULL;
}


/**
 * set_head_list - Update the head of  a linked list
 * @h_node: Node to set as head
 * @ch_node: The node to check for head
 * @list: Previous head of the linked list
*/
void set_head_list(listint_t *ch_node, listint_t *h_node, listint_t **list)
{
	if (ch_node == NULL)
		*list = h_node;
}

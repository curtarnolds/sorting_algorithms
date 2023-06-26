#include "sort.h"


/**
 * insertion_sort - Sort a doubly linked list of integers in ascending  order
 * @list: A doubly linked list of integers
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *inode, *node, *temp_next, *tnode_prev, *prev_node, *next_node;
	bool go_to_nxt_node;

	if (list == NULL || (*list)->next == NULL)
		return;

	node = *list;
	go_to_nxt_node = true;
	{
	while (node)
	{
		temp_next = node->next;
		if (node->next && node->n > node->next->n)
		{
			next_node = node->next;
			prev_node = node->prev;
			// swap nodes
			node->next = next_node->next;
			node->prev = next_node;

			if (next_node->next)
				next_node->next->prev = node;

			// swap next_node
			next_node->next = node;
			next_node->prev = prev_node;

			if (prev_node)
				prev_node->next = next_node;

			//backward comparison
			inode = node;
			while (inode)
			{
				tnode_prev = inode->prev;
				if (inode->prev && inode->n < inode->prev->n)
				{
					prev_node = inode->prev;
					next_node = inode->next;
					//swap nodes
					inode->prev = prev_node->prev;
					inode->next = prev_node;

					if (prev_node->prev)
						prev_node->prev->next = inode;

					// swap prev_node
					prev_node->prev = inode;
					prev_node->next = next_node;

					if (next_node)
						next_node->prev = prev_node;
				}
				inode = tnode_prev;
			}
			print_list(*list);
		}
		node = temp_next;
	}
	}
}



// void swap_nodes(listint_t *node, listint_t *next_node)
// {
// 	listint_t *temp, *prev_node, *next_two_nodes;

// 	if (!node || !next_node)
// 		return;

// 	// Get interesting nodes
// 	prev_node = node->prev;
// 	next_two_nodes = next_node->next;

// 	// Work on node
// 	node->prev = next_node;
// 	node->next = next_two_nodes;


// 	// Connect backwards
// 	if (next_two_nodes)
// 		next_two_nodes->prev = node;

// 	// Work on next_node
// 	next_node->prev = prev_node;
// 	next_node->next = node;

// 	// Connect backwards
// 	if (prev_node)
// 		prev_node->next = next_node;

// }

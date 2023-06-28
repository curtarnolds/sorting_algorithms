#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
size_t lomuto_part(int *array, size_t size, int start, int end);
void swap_arr(int *first, int *second, const int *array, size_t size);
void sort_algo(int *array, size_t size, int start, int end);
void shell_sort(int *array, size_t size);
void knuth_gen(int *gap_array, size_t size);
#endif

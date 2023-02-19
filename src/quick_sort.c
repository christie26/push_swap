/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:36:17 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/19 23:23:19 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	array_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return ;
}

void	array_print(int *array)
{
	printf("array is \n");
	for (int i = 0; i < 9; i++)
		printf("[%d] = %d\n", i, array[i]);
}

void	quick_sort(int *array, int start, int end)
{
	int i;
	int j;
	int mid;
	int	pivot;

//	printf("%d - %d\n", start, end);
	i = start + 1;
	j = end;
	mid = start + (end - start) / 2;
//	array_print(array);
//	printf("%d, %d, %d\n", start, mid, end);
	if (array[start] > array[mid])
		array_swap(array + start, array + mid);
//	printf("%d, %d, %d\n", array[start], array[mid], array[end]);
	if (array[start] > array[end])
		array_swap(array + start, array + end);
//	printf("%d, %d, %d\n", array[start], array[mid], array[end]);
	if (array[mid] > array[end])
		array_swap(array + mid, array + end);
//	printf("%d, %d, %d\n", array[start], array[mid], array[end]);
	array_swap(array + start, array + mid);
	pivot = array[start];
//	printf("pivot = %d\n", pivot);
	while (i < j)
	{
		while (pivot > array[i])
			i++;
		while (pivot < array[j])
			j--;
		if (i > j)
		{
			array_swap(array + start, array + j);
			break ;
		}
		array_swap(array + i, array + j);
	}
//	array_print(array);
	if (start + 1 < end)
	{
		quick_sort(array, start, j);
		quick_sort(array, j + 1, end);
	}
	return ;
}

int	*get_pivot(t_queue *a)
{
	int	idx;
	int	*array;
	int	*pivot;

	array = (int *)malloc(sizeof(int) * a->size);
	pivot = (int *)malloc(sizeof(int) * 2);
	idx = -1;
	while (idx < a->size)
	{	
		array[idx] = a->items[idx];
		idx++;
	}
	quick_sort(array, 0, a->size - 1);
	pivot[0] = array[a->size / 3];
	pivot[1] = array[a->size / 3 * 2];
//	array_print(array);
	return (pivot);
}

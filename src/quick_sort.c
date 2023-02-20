/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:36:17 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/20 10:52:10 by yoonsele         ###   ########.fr       */
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

void	quick_sort(int *array, int start, int end)
{
	int	i;
	int	j;
	int	mid;
	int	pivot;

	i = start + 1;
	j = end;
	mid = start + (end - start) / 2;
# if 1
	if (array[mid] > array[end])
		array_swap(array + mid, array + end);
	if (array[mid] > array[start])
		array_swap(array + mid, array + start);
	if (array[end] < array[start])
		array_swap(array + end, array + start);
# else
	if (array[start] > array[mid])
		array_swap(array + start, array + mid);
	if (array[start] > array[end])
		array_swap(array + start, array + end);
	if (array[mid] > array[end])
		array_swap(array + mid, array + end);
	array_swap(array + start, array + mid);
# endif
	pivot = array[start];
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
	if (start + 1 >= end)
		return ;
	quick_sort(array, start, j);
	quick_sort(array, j + 1, end);
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
	return (pivot);
}

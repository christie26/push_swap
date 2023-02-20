/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:36:17 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/20 14:21:46 by yoonsele         ###   ########.fr       */
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

void	put_pivot_start(int *array, int start, int end)
{
	int	mid;

	mid = start + (end - start) / 2;
	if (array[mid] > array[end])
		array_swap(array + mid, array + end);
	if (array[mid] > array[start])
		array_swap(array + mid, array + start);
	if (array[end] < array[start])
		array_swap(array + end, array + start);
	return ;
}

void	quick_sort(int *array, int start, int end)
{
	int	i;
	int	j;

	i = start + 1;
	j = end;
	put_pivot_start(array, start, end);
	while (i < j)
	{
		while (array[start] > array[i])
			i++;
		while (array[start] < array[j])
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

int	get_pivot(t_queue *a)
{
	int	idx;
	int	*array;
	int	pivot;

	idx = -1;
	array = (int *)malloc(sizeof(int) * a->size);
	if (!array)
		exit (1);
	while (idx++ < a->size)
		array[idx] = a->items[idx];
	quick_sort(array, 0, a->size - 1);
	pivot = array[a->size / 2];
	return (pivot);
}

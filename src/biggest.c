/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:24 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/16 16:40:50 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_leader(int i, int size, int group, int *big)
{
	while (i < size)
	{
		if (big[i] == group)
			return (i);
		i++;
	}
	return (0);
}

int	*alloc_index(int *array, int size, int i, int *max_group)
{
	int	j;
	int	group;
	int	*big;

	big = (int *)malloc(sizeof(int) * size);
	big[size - 1] = 1;
	while (i--)
	{
		group = *max_group + 1;
		while (--group)
		{
			j = find_leader(i, size, group, big);
			if (array[i] < array[j])
			{
				big[i] = group + 1;
				if (big[i] > *max_group)
					*max_group = big[i];
				break ;
			}
		}
		if (group == 0)
			big[i] = 1;
	}
	return (big);
}

int	minimum_value_index(int *big, int max_group, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (big[i] == max_group)
			return (i);
		i++;
	}
	printf("Error ! wrong with biggest\n");
	return (-1);
}

int	*biggest(t_queue	*a)
{
	int	*array;
	int	*big;
	int	size;
	int	i;
	int	max_group;

	max_group = 1;
	array = a->items;
	size = a->size;
	big = alloc_index(array, size, size - 1, &max_group);
	a->min_idx = minimum_value_index(big, max_group, size);
	i = -1;
	while (i++ < size)
	{
		if (big[i] != max_group)
			big[i] = 0;
		else
			max_group--;
	}
	return (big);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:24 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/15 12:43:27 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_index(int i, int size, int cmp, int *big)
{
	while (i < size)
	{
		if (big[i] == cmp)
			return (i);
		i++;
	}
	return (0);
}

int	*alloc_index(int *array, int size, int i, int max_idx)
{
	int	j;
	int	cmp;
	int	*big;

	big = (int *)malloc(sizeof(int) * size);
	big[size - 1] = 1;
	while (i--)
	{
		cmp = max_idx + 1;
		while (--cmp)
		{
			j = check_index(i, size, cmp, big);
			if (array[i] < array[j])
			{
				big[i] = cmp + 1;
				if (big[i] > max_idx)
					max_idx = big[i];
				break ;
			}
		}
		if (cmp == 0)
			big[i] = 1;
	}
	return (big);
}

int	*biggest(t_queue	*a)
{
	int	*array;
	int	*big;
	int	size;
	int	i;
	int	j;

	array = a->items;
	size = a->size;
	big = alloc_index(array, size, size - 1, 1);
	i = size;
	while (--i)
	{
		j = i;
		while (--j)
		{
			if (big[i] == big[j])
				big[i] = 0;
		}
	}
	return (big);
}

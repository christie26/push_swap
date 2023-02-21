/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:24 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/21 12:56:01 by yoonsele         ###   ########.fr       */
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

int	alloc_index(int *array, int size, int i, int *big)
{
	int	group;
	int	max_group;

	big[size - 1] = 1;
	max_group = 1;
	while (i--)
	{
		group = max_group + 1;
		while (--group)
		{
			if (array[i] < array[find_leader(i, size, group, big)])
			{
				big[i] = group + 1;
				if (big[i] > max_group)
					max_group = big[i];
				break ;
			}
		}
		if (group == 0)
			big[i] = 1;
	}
	return (max_group);
}

void	biggest(t_queue	*a, int *big)
{
	int	i;
	int	max_group;

	max_group = alloc_index(a->items, a->size, a->size - 1, big);
	a->min_idx = find_leader(0, a->size, max_group, big);
	i = -1;
	while (i++ < a->size)
	{
		if (big[i] != max_group)
			big[i] = 0;
		else
			max_group--;
	}
	return ;
}

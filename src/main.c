/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:28 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/20 14:25:01 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_queue *a, t_queue *b, int *big, int pivot)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (big[i])
			ra(a);
		else
		{
			if (a->items[i] < pivot)
				pb(a, b);
			else
			{
				pb(a, b);
				rb(b);
			}
		}
	i++;
	}
	free(big);
}

int	check_sorted(t_queue *a)
{
	int	i;
	int	*items;

	i = -1;
	items = a->items;
	while (i++ < a->size - 2)
	{
		if (items[i] > items[i + 1])
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_queue	*a;
	t_queue	*b;
	int		*big;
	int		pivot;

	if (ac == 1)
		return (1);
	a = get_queue(ac, av);
	if (!a)
		exit (1);
	if (check_sorted(a))
		exit (SORTED_INPUT);
	b = init_b(a->size);
	if (!b)
		exit (1);
	if (upto_five(a, b))
		return (0);
	big = biggest(a);
	if (!big)
		exit (1);
	pivot = get_pivot(a);
	move_to_b(a, b, big, pivot);
	back_to_a(a, b);
	minimum_top(a->min_idx, a);
}

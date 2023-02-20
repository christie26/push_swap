/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:28 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/20 16:18:05 by yoonsele         ###   ########.fr       */
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

int	set_queue(t_queue *a, t_queue *b, int ac, char **av)
{
	if (get_queue(ac, av, a))
		return (1);
	if (init_b(a->size, b))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_queue	a;
	t_queue	b;
	int		*big;
	int		pivot;

	if (ac == 1)
		return (1);
	if (set_queue(&a, &b, ac, av))
		exit (1);
	if (upto_five(&a, &b))
		return (0);
	big = (int *)malloc(sizeof(int) * a.size);
	if (!big)
		exit (1);
	biggest(&a, big);
	pivot = get_pivot(&a);
	move_to_b(&a, &b, big, pivot);
	back_to_a(&a, &b);
	minimum_top(a.min_idx, &a);
}

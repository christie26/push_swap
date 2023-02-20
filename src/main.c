/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:28 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/20 13:25:00 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/src/libft.h"

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
		return (EXIT_FAILURE);
	a = get_queue(ac, av);
	if (check_sorted(a))
		exit (SORTED_INPUT);
	b = init_b(a->size);
	if (upto_five(a, b))
		return (0);
	big = biggest(a);
	pivot = get_pivot(a);
	move_to_b(a, b, big, pivot);
	back_to_a(a, b);
	minimum_top(a->min_idx, a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:28 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/17 15:35:36 by yoonsele         ###   ########.fr       */
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

	if (ac == 1)
		return (EXIT_FAILURE);
	a = get_queue(ac, av);
	if (check_sorted(a))
		exit (SORTED_INPUT);
	b = init_b(a->size);
	big = biggest(a);
	move_to_b(a, b, big);
	back_to_a(a, b);
	rotate_center(a->min_idx, a, 1);
	print_queue(*a, *b);
}

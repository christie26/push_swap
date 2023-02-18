/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:35 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/18 22:46:12 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_queue *a, t_queue *b, int *big, int *pivot)
{
	int	i;
	int	one;
	int	two;

	i = 0;
	one = pivot[0];
	(void)one;
	two = pivot[1];
	while (i < a->size)
	{
		if (big[i])
			ra(a);
		else
		{
		//	if (one < a->items[i] && a->items[i] < two)
			if (a->items[i] < two)
				pb(a, b);
			else if (a->items[i] > two)
			{
				pb(a, b);
				rb(b);
			}
			else
				ra(a);
		}
	i++;
	}
}

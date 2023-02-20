/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:35 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/20 11:00:17 by yoonsele         ###   ########.fr       */
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
}

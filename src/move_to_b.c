/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:35 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/15 18:52:09 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_queue *a, t_queue *b, int *big)
{
	int	i;

	i = 0;
//	print_queue(*a, *b);
	while (i < a->size)
	{
		if (big[i])
			ra(a);
		else
			pb(a, b);
//		print_queue(*a, *b);
	i++;
	}
}

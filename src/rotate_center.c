/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_center.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:29:01 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/20 10:32:00 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_rrr(t_queue *a, t_queue *b, t_data *min)
{
	while (min->ra--)
		ra(a);
	while (min->rb--)
		rb(b);
	while (min->rr--)
		rr(a, b);
	while (min->rra--)
		rra(a);
	while (min->rrb--)
		rrb(b);
	while (min->rrr--)
		rrr(a, b);
	return ;
}

void	rotate_center(int idx, t_queue *queue, int flag)
{
	int	rotate;
	int	reverse;

	if (queue->front == queue->rear)
		return ;
	rotate = oversize(idx - queue->front, queue->size);
	reverse = oversize(queue->rear - idx + 1, queue->size);
	if (rotate < reverse)
	{
		while (rotate--)
		{
			if (flag == 1)
				ra(queue);
			else
				rb(queue);
		}
	}
	else
	{
		while (reverse--)
		{
			if (flag == 1)
				rra(queue);
			else
				rrb(queue);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_center.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:29:01 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/20 11:31:30 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	oversize(int value, int size)
{
	if (value < 0)
		return (value + size);
	else
		return (value);
}

void	update_a(t_queue *a)
{
	int	i;
	int	min;
	int	max;

	i = a->front;
	min = a->front;
	max = a->front;
	while (1)
	{
		if (a->items[min] > a->items[i])
			min = i;
		else if (a->items[max] < a->items[i])
			max = i;
		if (i == a->rear)
			break ;
		i = (i + 1) % a->size;
	}
	a->min_idx = min;
	a->max_idx = max;
	return ;
}

void	run_command(t_queue *a, t_queue *b, t_data *min)
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
	pa(a, b);
	update_a(a);
	return ;
}

void	minimum_top(int idx_a, t_queue *a)
{
	int	ra_num;
	int	rra_num;

	ra_num = oversize(idx_a - a->front, a->size);
	rra_num = oversize(a->rear - idx_a + 1, a->size);
	if (ra_num > rra_num)
		ra_num = 0;
	else
		rra_num = 0;
	while (ra_num--)
		ra(a);
	while (rra_num--)
		rra(a);
	return ;
}

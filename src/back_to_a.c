/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:42:47 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/20 10:33:21 by yoonsele         ###   ########.fr       */
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

void	update_min(t_queue *a)
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
	a->max = max;
	return ;
}

int	find_a_index(t_queue *a, int element_b)
{
	int	i;
	int	element;

	element = element_b + 1;
	while (element < a->items[a->max] + 1)
	{
		i = a->front;
		while (1)
		{
			if (a->items[i] == element)
				return (i);
			if (i == a->rear)
				break ;
			i = (i + 1) % a->size;
		}
		element++;
	}
	return (a->min_idx);
}

t_data	*set_cur_data(t_queue *a, t_queue *b, int idx_b, t_data *cur)
{
	int	idx_a;

	idx_a = find_a_index(a, b->items[idx_b]);
	cur->ra = oversize(idx_a - a->front, a->size);
	cur->rra = oversize(a->rear - idx_a + 1, a->size);
	cur->rb = oversize(idx_b - b->front, b->size);
	cur->rrb = oversize(b->rear - idx_b + 1, b->size);
	if (cur->ra > cur->rra)
		cur->ra = 0;
	else
		cur->rra = 0;
	if (cur->rb > cur->rrb)
		cur->rb = 0;
	else
		cur->rrb = 0;
	if (cur->ra && cur->rb)
	{
		if (cur->ra > cur->rb)
		{
			cur->rr = cur->rb;
			cur->ra = cur->ra - cur->rb;
			cur->rb = 0;
		}
		else
		{
			cur->rr = cur->ra;
			cur->rb = cur->rb - cur->ra;
			cur->ra = 0;
		}
	}
	if (cur->rra > cur->rrb)
	{
		cur->rrr = cur->rrb;
		cur->rra = cur->rra - cur->rrb;
		cur->rrb = 0;
	}
	else
	{
		cur->rrr = cur->rra;
		cur->rrb = cur->rrb - cur->rra;
		cur->rra = 0;
	}
	cur->total = cur->ra + cur->rb + cur->rr + cur->rra + cur->rrb + cur->rrr;
	return (cur);
}

void	back_to_a(t_queue *a, t_queue *b)
{
	t_data	min;
	t_data	cur;
	int		idx_b;
	int		min_b;

	update_min(a);
	while (b->front != -1)
	{
		ft_memset(&min, 0, sizeof(t_data));
		min.total = 2 * a->size;
		idx_b = b->front;
		min_b = idx_b;
		while (1)
		{
			ft_memset(&cur, 0, sizeof(t_data));
			set_cur_data(a, b, idx_b, &cur);
			if (cur.total < min.total)
				min = cur;
			if (idx_b == b->rear)
				break ;
			idx_b = (idx_b + 1) % b->size;
		}
		rr_rrr(a, b, &min);
		pa(a, b);
		update_min(a);
	}
}

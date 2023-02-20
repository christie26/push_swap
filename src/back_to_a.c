/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:42:47 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/20 11:31:33 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_a_index(t_queue *a, int element_b)
{
	int	i;
	int	element;

	element = element_b + 1;
	while (element < a->items[a->max_idx] + 1)
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

void	set_rr_rrr(int *a, int *b, int *r)
{
	if (*a > *b)
	{
		*r = *b;
		*a = *a - *b;
		*b = 0;
	}
	else
	{
		*r = *a;
		*b = *b - *a;
		*a = 0;
	}
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
		set_rr_rrr(&cur->ra, &cur->rb, &cur->rr);
	else if (cur->rra && cur->rrb)
		set_rr_rrr(&cur->rra, &cur->rrb, &cur->rrr);
	cur->total = cur->ra + cur->rb + cur->rr + cur->rra + cur->rrb + cur->rrr;
	return (cur);
}

void	back_to_a(t_queue *a, t_queue *b)
{
	t_data	min;
	t_data	cur;
	int		idx_b;
	int		min_b;

	update_a(a);
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
		run_command(a, b, &min);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:42:47 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/17 15:35:42 by yoonsele         ###   ########.fr       */
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

int	count_move(int idx, t_queue *queue)
{
	int	rotate;
	int	reverse;

	rotate = oversize(idx - queue->front, queue->size);
	reverse = oversize(queue->rear - idx + 1, queue->size);
	if (rotate < reverse)
		return (rotate);
	else
		return (reverse);
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

void	rotate_a(int element_b, t_queue *a)
{
	int	i;
	int	element;
	int	num_a;

	num_a = oversize(a->rear - a->front + 1, a->size);
	element = element_b + 1;
	while (num_a--)
	{
		i = a->front;
		while (1)
		{
			if (a->items[i] == element)
			{
				rotate_center(i, a, 1);
				return ;
			}
			if (i == a->rear)
				break ;
			i = (i + 1) % a->size;
		}
		element++;
	}
//	if (i == a->min_idx)
//		a->min_idx = a->front;
	rotate_center(a->min_idx, a, 1);
	return ;
}

int	count_move_a(int element_b, t_queue *a)
{
	int	i;
	int	element;
	int	num_a;

	num_a = oversize(a->rear - a->front + 1, a->size);
	element = element_b + 1;
	while (num_a--)
	{
		i = a->front;
		while (1)
		{
			if (a->items[i] == element)
				return (count_move(i, a));
			if (i == a->rear)
				break ;
			i = (i + 1) % a->size;
		}
		element++;
	}
	return (count_move(a->min_idx, a));
}

void	update_min(t_queue *a)
{
	int	i;
	int	min;

	i = a->front;
	min = a->front;
	while (1)
	{
		if (a->items[min] > a->items[i])
			min = i;
		if (i == a->rear)
			break;
		i = (i + 1) % a->size;
	}
	a->min_idx = min;
	return ;
}

void	back_to_a(t_queue *a, t_queue *b)
{
	int	tmp_b;
	int	idx_b;
	int	move;
	int	move_min;

	while (b->front != -1)
	{
		tmp_b = b->front;
		move_min = 2 * a->size;
		idx_b = tmp_b;
		while (1)
		{
			move = count_move(tmp_b, b);
			move += count_move_a(b->items[tmp_b], a);
			if (move < move_min)
			{
				idx_b = tmp_b;
				move_min = move;
			}
			if (tmp_b == b->rear)
				break ;
			tmp_b = (tmp_b + 1) % b->size;
		}
		rotate_center(idx_b, b, 2);
		rotate_a(b->items[idx_b], a);
		pa(a, b);
		update_min(a);
	}
}

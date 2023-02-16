/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:42:47 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/16 16:47:10 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_move(int idx, t_queue *queue)
{
	int	rotate;
	int	reverse;

	rotate = idx - queue->front;
	if (rotate < 0)
		rotate += queue->size;
	reverse = queue->rear - idx + 1;
	if (reverse < 0)
	{
		reverse += queue->size;
	}
//	printf("find_move\nrotate = %d, reverse = %d idx = %d\n", rotate, reverse, idx);
	if (rotate < reverse)
		return (rotate);
	else
		return (reverse);
}

void	rotate_b(int idx, t_queue *b)
{
	int	rotate;
	int	reverse;

	rotate = idx - b->front;
	if (rotate < 0)
		rotate += b->size;
	reverse = b->rear - idx + 1;
	if (reverse < 0)
	{
		reverse += b->size;
	}
	printf("push\nrotate = %d, reverse = %d idx = %d\n", rotate, reverse, idx);
	if (rotate < reverse)
	{
		while (rotate--)
			rb(b);
	}
	else
	{
		while (reverse--)
			rrb(b);
	}
}

int	find_move_a(int	element_b, t_queue *a)
{
	int	i;
	int	element;
	int	num_a;

	num_a = a->rear - a->front + 1;

	element = element_b + 1;
	while (num_a--)
	{
		i = a->front;
		while (i != a->rear)
		{
			if (a->items[i] == element)
				return (find_move(i, a));
			i = (i + 1) % a->size;
		}
		if (a->items[i] == element)
			return (find_move(i, a));
		element++;
	}
	printf("put smallest on the top\n");
	return (find_move(a->min_idx, a));
}

void	back_to_a(t_queue *a, t_queue *b)
{
	int	tmp_b;
	int	idx_b;
	int	move;
	int move_min;

	while (b->front != -1)
	{
		tmp_b = b->front;
		while (tmp_b != b->rear)
		{
			move = find_move(tmp_b, b);
			move += find_move_a(b->items[tmp_b], a);
			if (tmp_b == b->front)
			{
				printf("b->front = %d\n", b->front);
				move_min = move;
				idx_b = tmp_b;
			}
			else if (move < move_min)
			{
				idx_b = tmp_b;
				move_min = move;
			}
			tmp_b = (tmp_b + 1) % b->size;
		}
		move = find_move(tmp_b, b);
		move += find_move_a(b->items[tmp_b], a);
		if (move < move_min)
		{
			idx_b = tmp_b;
			move_min = move;
		}
		printf("move_min = %d, idx_b = %d\n", move_min, idx_b);
		rotate_b(idx_b, b);
	//	rotate_a();
		pa(a, b);
		print_queue(*a, *b);
	//	break ; // for test
	}
}

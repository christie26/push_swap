/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:42:47 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/15 19:37:33 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_move_b(int idx, t_queue *b)
{
	if (idx > b->front)
		return (idx - b->front);
	else
		return (idx - b->front + b->size);
	/*
	   move = idx - b->front;
	   if (move < 0)
	   move += b->size;
	   return (move);
	   */
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
				return (find_move_b(i, a));
			i = (i + 1) % a->size;
		}
		element++;
	}
	printf("put smallest on the top\n");
	return (-1);
}
void	move_b(t_queue *b, int idx_b)
{
	int	move;

	move = idx_b - b->front;
	if (move)
	{
		while (move--)
			rb(b);
	}
	else
	{
		move += b->size;
		while (move--)
			rrb(b);
	}
}

void	back_to_a(t_queue *a, t_queue *b)
{
	int tmp_b;
	int	idx_b;
	int	move;
	int move_min;

	while (b->front != -1)
	{
		tmp_b = b->front;
		move_min = 0;
		while (tmp_b != b->rear)
		{
			printf("tmp_b = %d \n", tmp_b);
			move = find_move_b(tmp_b, b);
			printf("check\n");
			move += find_move_a(b->items[tmp_b], a);
			printf("check\n");
			if (move < move_min)
			{
				idx_b = tmp_b;
				move_min = move;
			}
			//	if (tmp_b == b->rear)
			//	{
			//		printf("rear\n");
			//		break ;
			//	}
			tmp_b = (tmp_b + 1) % b->size ;
			printf("tmp_b -> %d\n", tmp_b);
		}
		printf("* tmp_b = %d \n", tmp_b);
		move = find_move_b(tmp_b, b);
		move += find_move_a(b->items[tmp_b], a);
		if (move < move_min)
		{
			idx_b = tmp_b;
			move_min = move;
		}
		printf("move_min = %d, idx_b = %d\n", move_min, idx_b);
		//	move_b(b, idx_b);
		//	print_queue(*a, *b);
		break ;
	}
}

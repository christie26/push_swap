/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:42:47 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/15 15:56:28 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move(t_queue *a, t_queue *b, int idx_a, idx_b)
{
	while (idx_b != b->front)
	


}

int	find_move_b(int idx, t_queue *b)
{
	int	move;

	move = idx - b->front;
	if (move < 0)
		move += b->size;
	return (move);
}

int	find_move_a(int	element_b, t_queue *a, int *idx_a)
{
	// we have to find element of stack a which is bigger than element_b and smallest at the same time 
}

void	back_to_a(t_queue *a, t_queue *b)
{
	int tmp_a;
	int tmp_b;
	int	idx_a;
	int	idx_b;
	int	move;
	int move_min;

	while (b->front != -1) // while b has elements
	{
		tmp_b = b->front;
		move_min = 0;
		while (tmp_b != b->rear)
		{
			move = find_move_b(tmp_b, b);
			move += find_move_a(b->items[tmp_b], a, &tmp_a);
			if (move < move_min)
			{
				idx_a = tmp_a;
				idx_b = tmp_b;
				move_min = move;
			}
			tmp_b = (tmp_b + 1) % b->size ;
		}
		move(a, b, idx_b);
	}
}

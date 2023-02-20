/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:50 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/20 11:33:37 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_queue *queue)
{
	int	tmp;

	tmp = queue->items[queue->rear];
	if (queue->rear == 0)
		queue->rear = queue->size - 1;
	else
		queue->rear = (queue->rear - 1) % queue->size;
	if (queue->front == 0)
		queue->front = queue->size - 1;
	else
		queue->front = (queue->front - 1) % queue->size;
	queue->items[queue->front] = tmp;
}

void	rra(t_queue *queue)
{
	rrotate(queue);
	write(1, &"rra\n", 4);
}

void	rrb(t_queue *queue)
{
	rrotate(queue);
	write(1, &"rrb\n", 4);
}

void	rrr(t_queue *a, t_queue *b)
{
	rrotate(a);
	rrotate(b);
	write(1, &"rrr\n", 4);
}

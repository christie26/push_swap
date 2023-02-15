/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:56:10 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/15 12:56:12 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_queue *queue)
{
	int	tmp;

	tmp = queue->items[queue->front];
	queue->front = (queue->front + 1) % queue->size;
	queue->rear = (queue->rear + 1) % queue->size;
	queue->items[queue->rear] = tmp;
}

void	ra(t_queue *queue)
{
	rotate(queue);
	write(1, &"ra\n", 3);
}

void	rb(t_queue *queue)
{
	rotate(queue);
	write(1, &"rb\n", 3);
}

void	rr(t_queue *a, t_queue *b)
{
	rotate(a);
	rotate(b);
	write(1, &"rr\n", 3);
}

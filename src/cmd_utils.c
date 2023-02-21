/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:38 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/21 12:56:07 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	en_queue(t_queue *queue, int element)
{
	if ((queue->front == queue->rear + 1) || \
			(queue->front == 0 && queue->rear == queue->size - 1))
		return ;
	if (queue->front == -1)
	{
		queue->front = 0;
		queue->rear = 0;
	}
	else
		queue->front = oversize(queue->front - 1, queue->size);
	queue->items[queue->front] = element;
}

int	de_queue(t_queue *queue)
{
	int	element;

	element = queue->items[queue->front];
	if (queue->front == queue->rear)
	{
		queue->front = -1;
		queue->rear = -1;
	}
	else
		queue->front = (queue->front + 1) % queue->size;
	return (element);
}

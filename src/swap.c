/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:56:13 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/15 12:56:17 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_queue *queue)
{
	int	tmp;
	int	next;

	if (queue->front == -1)
		return ;
	next = (queue->front + 1) % queue->size;
	if (next == queue->rear)
		return ;
	tmp = queue->items[queue->front];
	queue->items[queue->front] = queue->items[next];
	queue->items[next] = tmp;
}

void	sa(t_queue *queue)
{
	swap(queue);
	write(1, &"sa\n", 3);
}

void	sb(t_queue *queue)
{
	swap(queue);
	write(1, &"sb\n", 3);
}

void	ss(t_queue *a, t_queue *b)
{
	swap(a);
	swap(b);
	write(1, &"ss\n", 3);
}

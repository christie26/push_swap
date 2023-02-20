/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:38 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/20 10:36:07 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	en_queue(t_queue *queue, int element, int flag)
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
	{
		if (flag == FRONT)
		{
			if (queue->front == 0)
				queue->front = queue->size - 1;
			else
				queue->front = (queue->front - 1) % queue->size;
		}
		else
			queue->rear = (queue->rear + 1) % queue->size;
	}
	if (flag == FRONT)
		queue->items[queue->front] = element;
	else
		queue->items[queue->rear] = element;
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

void	print_queue(t_queue a, t_queue b)
{
	int		i;
	char	sta;
	char	stb;

	i = 0;
	sta = ' ';
	stb = ' ';
	printf("----------------\n");
	while (i < a.size)
	{
		if (i == a.front)
			sta = 'f';
		if (i == b.front)
			stb = 'f';
		if (i == a.rear)
			sta = 'r';
		if (i == b.rear)
			stb = 'r';
		printf("%2d %c %2d| %c %2d  |\n", i, sta, a.items[i], stb, b.items[i]);
		sta = ' ';
		stb = ' ';
		i++;
	}
	printf("----------------\n");
	printf(" i    a|    b  |\n");
	printf("----------------\n");
}

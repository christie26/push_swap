#include "push_swap.h"

void	en_queue(t_queue *queue, int element, int flag)
{
	if ((queue->front == queue->rear + 1) || \
		(queue->front == 0 && queue->rear == queue->size - 1))
	{
		write(1, &"Error: full\n", 12);
		return ;
	}
	if (queue->front == -1)
	{
		queue->front = 0;
		queue->rear = 0;
	}
	else
	{
		if (flag == FRONT)
			queue->front = (queue->front - 1) % queue->size;
		else
			queue->rear = (queue->rear + 1) % queue->size;
	}
	if (flag == FRONT)
		queue->items[queue->front] = element;
	else
		queue->items[queue->rear] = element;
//	printf("Insert -> %d\n", element);
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
//	printf("Delete -> %d\n", element);
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
		printf("%d %c %d| %c %d\n", i, sta, a.items[i], stb, b.items[i]);
		sta = ' ';
		stb = ' ';
		i++;
	}
	printf("    a |   b\n");
}

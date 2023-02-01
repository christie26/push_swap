
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define EXIT_FAILURE 1
# define FRONT 1
# define REAR 2

typedef struct s_queue {
	int	size;
	int	front;
	int	rear;
	int	*items;
}	t_queue;

void	sa(t_queue *queue);
void	sb(t_queue *queue);
void	pa(t_queue *a, t_queue *b);
void	pb(t_queue *a, t_queue *b);
void	ra(t_queue *queue);
void	rb(t_queue *queue);
int		de_queue(t_queue *queue);
void	en_queue(t_queue *queue, int element, int flag);
void	print_queue(t_queue a, t_queue b);

#endif

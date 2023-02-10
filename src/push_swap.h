#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/src/libft.h"

# define EXIT_FAILURE 1
# define SORTED_INPUT 1
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
void	rra(t_queue *queue);
void	rrb(t_queue *queue);
int		de_queue(t_queue *queue);
void	en_queue(t_queue *queue, int element, int flag);
t_queue	*get_queue(int ac, char **av);
t_queue	*init_b(int size);
void	print_queue(t_queue a, t_queue b);
int		*biggest(t_queue *a);
int		*parse_av(int ac, char **av, int size);
int		check_int(char *str);
int		check_over(int num, t_list **lst_ptr);
void	move_to_b(t_queue *a, t_queue *b, int *big);

#endif

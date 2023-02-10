#include "push_swap.h"

void	push(t_queue *src, t_queue *dst)
{
	int	element;

	element = de_queue(src);
	en_queue(dst, element, FRONT);
}

void	pa(t_queue *a, t_queue *b)
{
	push(b, a);
	write(1, &"pa\n", 3);
}

void	pb(t_queue *a, t_queue *b)
{
	push(a, b);
	write(1, &"pb\n", 3);
}

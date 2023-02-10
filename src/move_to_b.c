#include "push_swap.h"

void	move_to_b(t_queue *a, t_queue *b, int *big)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (big[i])
			ra(a);
		else
			pb(a, b);
	i++;
	}
}

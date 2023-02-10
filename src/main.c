#include "push_swap.h"
#include "../libft/src/libft.h"

int	get_size(int ac, char **av)
{
	int		cnt;
	int		i;
	int		j;

	cnt = 0;
	i = 1;
	while (i < ac)
	{
		cnt++;
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
				cnt++;
			j++;
		}
		i++;
	}
	return (cnt);
}

t_queue	*get_queue(int ac, char **av)
{
	int		size;
	int		*items;
	t_queue	*a;

	size = get_size(ac, av);
	items = parse_av(ac, av, size);
	a = ft_calloc(1, sizeof(t_queue));
	a->size = size;
	a->front = 0;
	a->rear = size - 1;
	a->items = items;
	return (a);
}

t_queue	*init_b(int size)
{
	int		*array;
	t_queue	*b;

	array = (int *)malloc(sizeof(int) * size);
	b = ft_calloc(sizeof(t_queue), 1);
	b->items = array;
	b->front = -1;
	b->rear = -1;
	b->size = size;
	return (b);
}

int	main(int ac, char **av)
{
	t_queue	*a;
	t_queue	*b;

	if (ac == 1)
		return (EXIT_FAILURE);
	a = get_queue(ac, av);
	b = init_b(a->size);
	biggest(a);
	(void)b;
/*
//	test to check operations	
	print_queue(*a, *b);
	sa(a);
	print_queue(*a, *b);
	printf("\n");
	pb(a, b);
	print_queue(*a, *b);
	printf("\n");

	pa(a, b);
	print_queue(*a, *b);
	printf("\n");

	pa(a, b);
	print_queue(*a, *b);
	printf("\n");

	ra(a);
	print_queue(*a, *b);
	printf("\n");
	rra(a);
	print_queue(*a, *b);
*/
}

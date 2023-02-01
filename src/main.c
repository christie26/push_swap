#include "push_swap.h"
#include "../libft/libft.h"

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

int	*parsing(int ac, char **av, int size)
{
	int		*items;
	char	**tab;
	char	**tmp;
	int		i;

	items = (int *)malloc(sizeof(int) * size);
	i = 1;
	while (i < ac)
	{
		tab = ft_split(av[i], ' ');
		tmp = tab;
		while (*tab)
		{
			*items = ft_atoi(*tab);
			items++;
			tab++;
		}
		free(tmp);
		i++;
	}
	items -= size;
	return (items);
}

t_queue	*get_queue(int ac, char **av)
{
	int		size;
	int		*items;
	t_queue	*a;

	size = get_size(ac, av);
	items = parsing(ac, av, size);
	a = ft_calloc(1, sizeof(t_queue));
	a->size = size;
	a->front = 0;
	a->rear = size - 1;
	a->items = items;
	return (a);
}

int	main(int ac, char **av)
{
	t_queue	*a;
	t_queue	*b;
	int		*array;

	if (ac == 1)
		return (EXIT_FAILURE);
	a = get_queue(ac, av);
	array = (int *)malloc(sizeof(int) * a->size);
	b = ft_calloc(sizeof(t_queue), 1);
	b->items = array;
	b->front = -1;
	b->rear = -1;
	b->size = a->size;
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
}

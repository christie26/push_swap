#include "push_swap.h"
#include "../libft/libft.h"

void	get_queue(int ac, char **av)
{
	int	cnt;
	int	i;
	int	j;
	int	*queue;
	char	*tab;

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
//	printf("cnt = %d\n", cnt);
	queue = (int *)malloc(sizeof(int) * cnt);
	i = 1;
	while (i < ac)
	{
		tab = ft_split(av[i], ' ');
		while (*tab)
		{
			*queue = ft_atoi(*tab);
			queue++;
			tab++;
		}
		free(tab);
		i++;
	}	
}
// read av and put the data to stack until it ends 

int	main(int ac, char **av)
{
	t_queue	que_a;

	if (ac == 1)
		return (EXIT_FAILURE);
	get_queue(ac, av);
}

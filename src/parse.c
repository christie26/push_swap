/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:41 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/20 16:16:33 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_message(t_list *head, int *a, int *b)
{
	// head free
	if (a)
		free(a);
	if (b)
		free(b);
	write(2, "Error\n", 6);
	return (1);
}

int	parse_av(int ac, char **av, int *items)
{
	int		i;
	int		cnt;
	char	**tab;
	t_list	*head;

	head = NULL;
	i = 0;
	while (++i < ac)
	{
		tab = ft_split(av[i], ' ');
		cnt = 0;
		while (*tab)
		{
			*items = ft_atoi(*tab);
			if (check_over(*items, &head) || check_int(*tab))
				return (error_message(head, items, 0));
			items++;
			tab++;
			cnt++;
		}
		free(tab - cnt);
	}
	// free head 
	return (0);
}

int	get_size(int ac, char **av)
{
	int		cnt;
	int		i;
	int		j;

	cnt = 0;
	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j++] != ' ')
			cnt++;
		while (av[i][j])
		{
			if (av[i][j] != ' ' && av[i][j - 1] == ' ')
				cnt++;
			j++;
		}
		i++;
	}
	return (cnt);
}

int	get_queue(int ac, char **av, t_queue *a)
{
	int	size;
	int	*items;

	size = get_size(ac, av);
	items = (int *)malloc(sizeof(int) * size);
	if (!items)
		return (1);
	if (parse_av(ac, av, items))
		return (1);
	a->items = items;
	a->size = size;
	a->front = 0;
	a->rear = size - 1;
	return (0);
}

int	init_b(int size, t_queue *b)
{
	b->items = (int *)malloc(sizeof(int) * size);
	if (!b->items)
		return (1);
	b->front = -1;
	b->rear = -1;
	b->size = size;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:41 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/21 13:08:46 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_message(t_pslst *head, int *items)
{
	if (head)
		ps_lstclear(&head);
	if (items)
		free(items);
	write(2, "Error\n", 6);
	return (1);
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

int	parse_av(int ac, char **av, int *items, t_pslst **head)
{
	int		i;
	int		j;
	char	**tab;
	char	**tmp;

	i = 0;
	j = 0;
	while (++i < ac)
	{
		tab = ft_split(av[i], ' ');
		tmp = tab;
		while (*tmp)
		{
			items[j] = ft_atoi(*tmp);
			if (check_over(items[j], head) || check_int(*tmp))
			{
				ft_free(tab);
				return (error_message(*head, items));
			}
			j++;
			tmp++;
		}
		ft_free(tab);
	}
	return (0);
}

int	get_queue(int ac, char **av, t_queue *a)
{
	int		size;
	int		*items;
	t_pslst	*head;

	head = NULL;
	size = get_size(ac, av);
	items = (int *)malloc(sizeof(int) * size);
	if (!items)
		return (1);
	if (parse_av(ac, av, items, &head))
		return (1);
	if (head)
		ps_lstclear(&head);
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

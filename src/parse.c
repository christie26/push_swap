/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:41 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/20 14:24:19 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_over(int num, t_list **lst_ptr)
{
	t_list	*curr;
	t_list	*newlist;
	int		*ptr;
	int		*content;

	ptr = (int *)malloc(sizeof(int));
	*ptr = num;
	if (!(*lst_ptr))
	{
		*lst_ptr = ft_lstnew((void *)ptr);
		return (0);
	}
	curr = *lst_ptr;
	while (curr)
	{
		content = curr->content;
		if (*content == num)
			return (1);
		else
			curr = curr->next;
	}
	newlist = ft_lstnew((void *)ptr);
	ft_lstadd_back(lst_ptr, newlist);
	return (0);
}

int	*parse_av(int ac, char **av, int size)
{
	int		*items;
	char	**tab;
	int		i;
	int		cnt;
	t_list	*head;

	items = (int *)malloc(sizeof(int) * size);
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
				exit (1);
			items++;
			tab++;
			cnt++;
		}
		free(tab - cnt);
	}
	return (items - size);
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

t_queue	*get_queue(int ac, char **av)
{
	int		size;
	int		*items;
	t_queue	*a;

	size = get_size(ac, av);
	items = parse_av(ac, av, size);
	a = ft_calloc(1, sizeof(t_queue));
	if (!a)
		return (0);
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
	if (!b)
		return (0);
	b->items = array;
	b->front = -1;
	b->rear = -1;
	b->size = size;
	return (b);
}

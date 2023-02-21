/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:26:00 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/21 12:56:08 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pslst	*ps_lstnew(int content)
{
	t_pslst	*new;

	new = malloc(sizeof(t_pslst));
	if (!new)
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}

void	ps_lstadd_back(t_pslst **lst, t_pslst *node)
{
	t_pslst	*head;

	head = *lst;
	if (!lst || !node)
		return ;
	if (*lst)
	{
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = node;
		*lst = head;
	}
	else
		*lst = node;
	return ;
}

void	ps_lstclear(t_pslst **lst)
{
	t_pslst	*tmp;

	if (!(*lst) || !lst)
		return ;
	tmp = *lst;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

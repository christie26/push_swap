/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:44 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/20 16:07:13 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/src/libft.h"

static int	is_space(char c)
{
	if (c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == '\t' || c == ' ')
		return (1);
	else
		return (0);
}

static int	is_sign(char c, int *sign)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			(*sign)++;
		return (1);
	}
	else
		return (0);
}

int	check_int(char *str)
{
	size_t		i;
	long long	sum;
	int			sign;

	i = 0;
	sum = 0;
	sign = 0;
	while (is_space(str[i]) == 1)
		i++;
	if (is_sign(str[i], &sign) == 1)
		i++;
	while (('0' <= str[i]) && (str[i] <= '9'))
	{
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	if (sign == 1)
		sum = -sum;
	if (i != ft_strlen(str) || ft_strlen(str) > 11)
		return (1);
	if (sum > INT_MAX || sum < INT_MIN)
		return (1);
	return (0);
}

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

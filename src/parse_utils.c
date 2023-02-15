/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:44 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/15 12:43:46 by yoonsele         ###   ########.fr       */
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
	if (i != ft_strlen(str))
		return (1);
	if (sum > INT_MAX || sum < INT_MIN)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upto_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:37:13 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/20 13:47:01 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	two_sort(t_queue *a)
{
	int	*array;

	array = a->items;
	if (array[0] > array[1])
		sa(a);
	return (1);
}

int	three_sort(t_queue *a, int offset)
{
	int	*array;

	array = a->items + offset;
	if (array[2] < array[0] && array[2] < array[1])
	{
		if (array[0] > array[1])
			sa(a);
		rra(a);
	}
	else if (array[2] > array[0] && array[2] > array[1])
	{
		if (array[0] > array[1])
			sa(a);
	}
	else
	{
		if (array[0] < array[1])
			sa(a);
		ra(a);
	}
	return (1);
}

int	five_sort(t_queue *a, t_queue *b)
{
	t_data	one;

	pb(a, b);
	pb(a, b);
	three_sort(a, 2);
	update_a(a);
	ft_memset(&one, 0, sizeof(t_data));
	set_cur_data(a, b, b->front, &one);
	run_command(a, b, &one);
	ft_memset(&one, 0, sizeof(t_data));
	set_cur_data(a, b, b->front, &one);
	run_command(a, b, &one);
	minimum_top(a->min_idx, a);
	return (1);
}

int	upto_five(t_queue *a, t_queue *b)
{
	if (a->size > 5)
		return (0);
	else if (a->size == 2)
		return (two_sort(a));
	else if (a->size == 3)
		return (three_sort(a, 0));
	else
		return (five_sort(a, b));
}

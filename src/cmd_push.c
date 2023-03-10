/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:43:47 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/21 12:56:03 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_queue *src, t_queue *dst)
{
	int	element;

	if (src->front == -1)
		return ;
	element = de_queue(src);
	en_queue(dst, element);
}

void	pa(t_queue *a, t_queue *b)
{
	push(b, a);
	write(1, &"pa\n", 3);
}

void	pb(t_queue *a, t_queue *b)
{
	push(a, b);
	write(1, &"pb\n", 3);
}

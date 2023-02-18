/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:36:17 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/18 22:46:07 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_queue *a, int *big)
{
	int	max_group;
	int	i;
	int	size;

	i = 0;
	while (big[i] == 0)
		i++;
	max_group = big[i];
//	printf("we have %d sorted array\n", max_group);
	
	(void)a;
	return ;
}

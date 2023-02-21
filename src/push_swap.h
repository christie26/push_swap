/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:57:14 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/21 12:59:37 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/src/libft.h"

# define EXIT_FAILURE 1
# define FRONT 1
# define REAR 2

typedef struct s_pslst {
	int				content;
	struct s_pslst	*next;
}	t_pslst;

typedef struct s_data {
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_data;

typedef struct s_queue {
	int	size;
	int	front;
	int	rear;
	int	min_idx;
	int	max_idx;
	int	*items;
}	t_queue;

t_pslst	*ps_lstnew(int content);
void	ps_lstadd_back(t_pslst **lst, t_pslst *node);
void	ps_lstclear(t_pslst **lst);

void	sa(t_queue *queue);
void	sb(t_queue *queue);
void	pa(t_queue *a, t_queue *b);
void	pb(t_queue *a, t_queue *b);
void	ra(t_queue *queue);
void	rb(t_queue *queue);
void	rr(t_queue *a, t_queue *b);
void	rra(t_queue *queue);
void	rrb(t_queue *queue);
void	rrr(t_queue *a, t_queue *b);
int		de_queue(t_queue *queue);
void	en_queue(t_queue *queue, int element);

int		get_queue(int ac, char **av, t_queue *a);
int		parse_av(int ac, char **av, int *items, t_pslst **head);
int		init_b(int size, t_queue *b);

int		check_int(char *str);
int		check_over(int num, t_pslst **lst_ptr);
int		upto_five(t_queue *a, t_queue *b);
void	biggest(t_queue *a, int *big);

int		get_pivot(t_queue *a);
void	quick_sort(int *array, int start, int end);

void	ft_free(char **tab);
int		oversize(int value, int size);
void	back_to_a(t_queue *a, t_queue*b);
t_data	*set_cur_data(t_queue *a, t_queue *b, int idx_b, t_data *cur);
void	run_command(t_queue *a, t_queue *b, t_data *min);
void	update_a(t_queue *a);
int		find_a_index(t_queue *a, int element_b);
void	minimum_top(int idx_a, t_queue *a);

void	print_queue(t_queue a, t_queue b);

#endif

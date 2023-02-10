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

void print_llist(t_list *head);

int	check_over(int num, t_list **lst_ptr)
{
	t_list	*head;
	t_list	*curr;
	t_list	*newlist;
	int		*ptr;
	int		*content;

//	printf("aaaa\n");
	print_llist(*lst_ptr);

//	printf("bbbb\n");
	head = *lst_ptr;
	ptr = (int *)malloc(sizeof(int));
	*ptr = num;
//	content = head->content;
//	printf("head->content = %d\n", *content);
	if (!head)
	{
		printf("nothing in head\n");
//		head = ft_lstnew((void *)ptr);
		*lst_ptr = ft_lstnew((void *)ptr);
		return (0);
	}
	curr = head;
	while (curr)
	{
		content = curr->content;
		printf("curr->content = %d\n", *content);
		printf("num = %d\n", num);
		if (*content == num)
			return (1);
		else
			curr = curr->next;
	}
	newlist = ft_lstnew((void *)ptr);
	ft_lstadd_back(lst_ptr, newlist);
	return (0);
}


void print_llist(t_list *head)
{
	t_list *cur;

	cur = head;
	while (cur)
	{
		printf("(%d) -> ", *((int*)cur->content));
		cur = cur->next;	
	}
	printf("NULL\n");


}

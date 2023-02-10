#include "push_swap.h"

/*
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
*/

int	check_over(int num, t_list **lst_ptr)
{
	t_list	*curr;
	t_list	*newlist;
	int		*ptr;
	int		*content;

//	print_llist(*lst_ptr);
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
	t_list	*head;

	items = (int *)malloc(sizeof(int) * size);
	head = NULL;
	i = 0;
	while (++i < ac)
	{
		tab = ft_split(av[i], ' ');
		while (*tab)
		{
			if (check_int(*tab))
				exit (1);
			*items = ft_atoi(*tab);
			if (check_over(*items, &head))
				exit (1);
			items++;
			tab++;
		}
		free(tab - size);
	}
	return (items - size);
}

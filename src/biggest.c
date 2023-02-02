#include "push_swap.h"

//cmp 가 적혀있는 수들 중에 가장 큰 수의 인덱스 반환
int	max_idx(int i, int size, int cmp, int *big)
{
	while(i < size)
	{
		if (big[i] == cmp)
			return (i);
		i++;
	}
	return (0);
}

void	biggest(t_queue	*a)
{
	int	*array;
	int	*big;
	int	size;
	int	max;
	int	cmp;
	int	i;
	int	j;

	array = a->items;
	size = a->size;
	big = (int *)malloc(sizeof(int) * size);
	big[size - 1] = 1;
	i = size - 1;
	max = 1;
	while (i--)
	{
		cmp = max + 1;
		while (--cmp)
		{
			j = max_idx(i, size, cmp, big);
			if (array[i] < array[j])
			{
				big[i] = cmp + 1;
				if (big[i] > max)
					max = big[i];
				break;
			}
		}
		if (cmp == 0)
			big[i] = 1;
	}
	printf("result of biggest\n");
	for(int i=0; i < size; i++)
		printf("items[%d]=%d, %d\n",i, array[i],big[i]);	
}

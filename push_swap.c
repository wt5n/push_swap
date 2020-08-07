#include "push_swap.h"
#include "./libft/libft.h"

static void initialize(t_stack *numbs)
{
	numbs->steps = 0;
	if (!(numbs->b = (int *)malloc(sizeof(numbs->n-1))))
		exit(1);
}

void ft_sort(t_stack *numbs)
{
	if (numbs->n == 1)
		return ;
	else if (numbs->n == 2)
		if(numbs->a[0] > numbs->a[1])
			ft_sa(numbs);
//	else if (numbs->n > 5)
//			ft_sorting(numbs);
}

void ft_sorting(numbs)
{

}

int main()
{
	t_stack *numbs;
	int ac = 2;
	char *av[] = {"push_swap", "5\t1"};
	if(ac < 2)
		exit(1);
	if (!(numbs = (t_stack *)malloc(sizeof(t_stack))))
		exit(1);
	numbs->n;
	if(validation(ac, av, numbs))
	{
		initialize(numbs);
		if(numbs->unsorted == 1)
			ft_sort(numbs);
		for(int i = 0; i < numbs->n; i++)
			printf("%d ", numbs->a[i]);
	}
	free(numbs);
	return 0;
}

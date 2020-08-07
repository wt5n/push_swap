#include "push_swap.h"
#include "./libft/libft.h"

static void initialize(t_stack *numbs)
{
	numbs->steps = 0;
	numbs->unsorted = 0;
	if (!(numbs->b = (int *)malloc(sizeof(numbs->a))))
		exit(1);
}


int main()
{
	t_stack *numbs;
	int ac = 5;
	char *av[] = {"push_swap", "1 2 7", "4", "5", "3", "-1"};
	if(ac < 2)
		exit(1);
	if (!(numbs = (t_stack *)malloc(sizeof(t_stack))))
		exit(1);
	numbs->n = 0;
	if(validation(ac, av, numbs))
	{
		initialize(numbs);
		if(numbs->unsorted)
			ft_sort(numbs);
	}
	free(numbs);
	return 0;
}

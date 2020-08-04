#include "push_swap.h"
int main(int ac, char **av)
{
	int i = 1;
	while (i < ac)
	{
		printf("%s, %d\n", av[i], i);
		i++;
	}
	return 0;
}

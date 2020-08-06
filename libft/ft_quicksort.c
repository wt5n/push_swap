#include "./libft.h"

static int partition(int *A, int p, int q)
{
	int i = p - 1;
	int j = p;
	while (j <= q)
	{
		if(A[j] <= A[q])
			ft_swap(&A[++i], &A[j]);
		j++;
	}
	return i;
}

void ft_quicksort(int *A, int p, int q)
{
	if(p < q)
	{
		int pivot = partition(A, p, q);
		ft_quicksort(A, p, pivot - 1);
		ft_quicksort(A, pivot + 1, q);
	}
}
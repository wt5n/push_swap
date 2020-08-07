#include "push_swap.h"

int	*ft_intcpy(int *str1, int *str2, int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	str1[i] = str2[i];
	return (str1);
}
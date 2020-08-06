int	*ft_intcpy(int *str1, const t_stack *str2)
{
	unsigned int i;

	i = 0;
	while (i < numbs->n)
	{
		str1[i] = numbs->a[i];
		i++;
	}
	str1[i] = numbs->a[i];
	return (str1);
}
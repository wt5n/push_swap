#include "push_swap.h"
#include "./libft/libft.h"

t_stack	*init_stack(const int *stack, int n)
{
	t_stack *a;
	t_stack *b;
	int i;

	i = 0;
	if (!(a = (t_stack *)malloc(sizeof(t_stack))))
		exit(1);
	b = a;
	while (i < n)
	{
		if (i < n -1)
			if(!(a->next = (t_stack *)malloc(sizeof(t_stack))))
				exit(1);
		a->value = stack[i];
		if(i == (n - 1))
			a->next = NULL;
		else
			a = a->next;
		i++;
	}
	return (b);
}

static void initialize(t_info *numbs, t_stacks *res)
{
	res->b = NULL;
	res->a = init_stack(numbs->a, numbs->n);
	res->len_a = numbs->n;
	res->len_b = 0;
	res->max = 0;
	res->min = 0;
}

void	sort_3(t_stacks *res)
{
	res->max = res->a->value;
	while (res->a)
	{
		if (res->a->value > res->max)
			res->max = res->a->value;
		res->a = res->a->next;
	}
	if (res->len_a == 2)
		if (res->a->value > res->a->next->value)
			ft_sa(res->a);
	if (res->len_a == 3)
	{
		if (res->a->value == res->max)
			ft_ra(&res->a);
		if (res->a->next->value == res->max)
			fr_rra(&res->a);
		if (res->a->value > res->a->next->value)
			ft_sa(res->a);
	}
}

void	sort_5(t_stacks *res)
{

}

void ft_sort(t_stacks *res)
{
	if (res->len_a == 1)
		return ;
	else if (res->len_a <= 3)
		sort_3(res);
	else if (res->len_a <= 5)
		sort_5(res);
	else
		ft_sorting(res);
}

//void ft_sorting(numbs)
//{
//
//}

void print_int(int *a, int n)
{
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
}

int main(int ac, char **av)
{
	t_info *numbs;
	t_stacks *res;
	if(ac < 2)
		exit(1);
	if (!(numbs = (t_info *)malloc(sizeof(t_info))))
		exit(1);
	if (!(res = (t_stacks *)malloc(sizeof(t_stacks))))
		exit(1);
	if(validation(ac, av, numbs)) // проверка на пустой аргумент, цифры/буквы, дубликаты. Сохраняем готовый массив из чисел в общую структуру
	{
		initialize(numbs, res); // перевод из общего массива после проверок к листам
		if(numbs->unsorted == 1) // Если не отсортирован, отправляем на сортировку
			ft_sort(res);
	}
	free(numbs);
	free(res);
	return 0;
}

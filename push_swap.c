#include "push_swap.h"

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
	res->max = numbs->a[numbs->n - 1];
	res->min = numbs->a[0];
	res->print_comm = 1;
}

void ft_sorting(t_stacks *res)
{
	printf("ok\n");
}

int		ft_max(t_stack *s)
{
	int max;

	max = s->value;
	while (s)
	{
		if (s->value > max)
			max = s->value;
		s = s->next;
	}
	return (max);
}

void	sort_3(t_stacks *res)
{
	res->max = ft_max(res->a);
	if (res->len_a == 2)
		if (res->a->value > res->a->next->value)
			ft_sa(res->a, res->print_comm);
	if (res->len_a == 3)
	{
		if (res->a->value == res->max)
			ft_ra(&res->a, res->print_comm);
		if (res->a->next->value == res->max)
			ft_rra(&res->a, res->print_comm);
		if (res->a->value > res->a->next->value)
			ft_sa(res->a, res->print_comm);
	}
}

void	sort_5(t_stacks *res)
{
	while (res->len_b < 2)
		(res->a->value == res->min || res->a->value == res->max)? \
		ft_pb(res, res->print_comm) : ft_ra(&res->a, res->print_comm);
	sort_3(res);
	ft_pa(res, res->print_comm);
	ft_pa(res, res->print_comm);
	if (res->a->value == res->max)
		ft_ra(&res->a, res->print_comm);
	else
	{
		ft_sa(res->a, res->print_comm);
		ft_ra(&res->a, res->print_comm);
	}
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
			ft_sort(res); // вывод команд для сортировки
	}
	free(numbs);
	free(res);
	return 0;
}

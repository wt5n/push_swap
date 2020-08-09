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
	res->max = numbs->a[numbs->n - 1];
	res->min = numbs->a[0];
	res->print_comm = 0;
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

void	actions(char *line, t_stacks *res)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_sa(res->a, 0);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sb(res->b, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ft_ss(res, 0);
	else if (ft_strcmp(line, "pa") == 0)
		ft_pa(res, 0);
	else if (ft_strcmp(line, "pb") == 0)
		ft_pb(res, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ft_ra(&res->a, 0);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rb(&res->b, 0);
	else if (ft_strcmp(line, "rr") == 0)
		ft_rr(res, 0);
	else if (ft_strcmp(line, "rra") == 0)
		ft_rra(&res->a, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rrb(&res->b, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rrr(res, 0);
	else
		ft_error();
}

void	read_line(t_stacks *res)
{
	char *str;

	str = NULL;
	while (get_next_line(0, &str))
	{
		actions(str,res);
		free(str);
		str = NULL;
	}
	if (str)
	{
		free(str);
		str = NULL;
	}
}

int stack_sort(t_stacks *res)
{
	int i;
	t_stack *s;
	int buff;

	i = 0;
	s = res->a;
	while (i < (res->len_a - 1))
	{
		buff = res->a->value;
		res->a = res->a->next;
		if (buff > res->a->value)
		{
			res->a = s;
			return (0);
		}
		i++;
	}
	res->a = s;
	return (1);
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
		read_line(res);
		if (stack_sort(res) && res->len_b == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free(numbs);
	free(res);
	return 0;
}

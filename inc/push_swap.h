/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:06:18 by hlikely           #+#    #+#             */
/*   Updated: 2020/08/10 17:43:45 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct		s_info
{
	int				a[5000];
	int				n;
	int				unsorted;
	int				max;
	int				min;
	int				med;
}					t_info;

typedef struct		s_stack
{
	int				value;
	int				step;
	int				rotate;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stacks
{
	t_stack			*a;
	t_stack			*b;
	int				len_a;
	int				len_b;
	int				max;
	int				min;
	int				med;
	int				print_comm;
	int				slen_a;
	int				slen_b;
	int				dest_a;
	int				dest_b;
}					t_stacks;

int					spaces_check(int ac, const char *av);
t_stack				*init_stack(const int *stack, int n);
void				initialize(t_info *numbs, t_stacks *res);
void				to_info(t_info numbs, int *buff, int n_word);
void				number_validation(const char *av);
int					validation(int ac, char **av, t_info *numbs);
void				check_duplicate(t_info *numbs);
void				transformation(int ac, char **av, t_info *numbs);
void				ft_sa(t_stack *a, int print_comm);
void				ft_sb(t_stack *a, int print_comm);
void				ft_ss(t_stacks *res, int print_comm);
void				ft_ra(t_stack **a, int print_comm);
void				ft_rb(t_stack **a, int print_comm);
void				ft_rr(t_stacks *res, int print_comm);
void				ft_rra(t_stack **a, int print_comm);
void				ft_rrb(t_stack **a, int print_comm);
void				ft_rrr(t_stacks *res, int print_comm);
void				ft_pa(t_stacks *res, int print_comm);
void				ft_pb(t_stacks *res, int print_comm);
void				ft_sorting(t_stacks *res);
void				ft_instruction_execution(t_stacks *res, t_stacks *steps);
void				ft_start_sort(t_stacks *res);
void				ft_minimum_insertion_steps(t_stacks *res, t_stacks *steps);
void				ft_steps_markup(t_stack *b, int count);
int					ft_smaller_element_detection(t_stack *a, int buff, int src);
void				ft_help_finding_place(t_stacks *s, t_stack *b, int *action, int *buff);
int					ft_finding_place(t_stacks *s, t_stack *b, t_stacks *steps, int min);
int					ft_count_to_min(t_stack *a, int min);

#endif

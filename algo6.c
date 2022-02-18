/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:36:44 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/06 15:36:52 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	help_else_sort(t_list *tmp, t_list *a, t_list *b, int med_e)
{
	int	min_elem_stack;
	int	max_elem_stack;

	min_elem_stack = min_elem(a);
	max_elem_stack = max_elem(a);
	if (tmp->value != max_elem_stack && tmp->value != min_elem_stack)
	{
		pb(tmp, b);
		if (b->value > med_e)
			rb(b);
	}
	else
		ra(a);
}

static void	count_score_help(t_list *a, t_list *b, int min_elem)
{
	count_score_b(b);
	count_score_a(a, b, min_elem);
	push_to_a(a, b);
}

static void	else_sort_help(t_list *b, t_list *a, int min_e)
{
	while (b)
	{
		if (!b->next)
		{
			count_score_help(a, b, min_e);
			break ;
		}
		count_score_help(a, b, min_e);
	}
}

void	else_sort(t_list *a, int new_argc)
{
	int		min_elem_stack;
	int		max_elem_stack;
	int		med_elem_stack;
	t_list	*b;
	t_list	*tmp;

	min_elem_stack = min_elem(a);
	max_elem_stack = max_elem(a);
	med_elem_stack = med(a, new_argc);
	b = init_b_first_push(a, max_elem_stack, min_elem_stack);
	tmp = a;
	while (argc_call(a) != 2)
		help_else_sort(tmp, a, b, med_elem_stack);
	if (a->value == min_elem_stack)
		ra(a);
	else_sort_help(b, a, min_elem_stack);
	while (!sort_check_final(a))
		rra_and_ra(a, new_argc, min_elem_stack);
}

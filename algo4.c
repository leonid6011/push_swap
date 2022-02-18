/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:07:03 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/06 13:07:14 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_b_first_push(t_list *a, int max_elem_stack, int min_elem_stack)
{
	t_list	*b;
	t_list	*tmp_a;

	tmp_a = a;
	tmp_a = tmp_a->next;
	if (a->value == max_elem_stack || a->value == min_elem_stack)
		ra(a);
	if (a->value == max_elem_stack || a->value == min_elem_stack)
		ra(a);
	b = start(a->value);
	pb(a, b);
	del_first_elem(b);
	return (b);
}

void	count_score_b(t_list *b)
{
	int	i;
	int	count;
	int	argc;

	argc = argc_call(b);
	count = argc / 2;
	i = 0;
	while (b)
	{
		if (i <= count)
			b->score_b = i;
		else
			b->score_b = i - argc;
		i++;
		b = b->next;
	}
}

void	count_score_a_plus(t_list *a, t_list *tmp_b)
{
	t_list	*tmp_a;
	int		count;

	count = 0;
	tmp_a = a;
	while (tmp_a->value < tmp_b->value)
	{
		count++;
		tmp_a = tmp_a->next;
	}
	tmp_b->score_a = count;
}

void	count_score_a_minus(t_list *a, t_list *tmp_b, int min_e)
{
	t_list	*tmp_a;
	int		count;

	count = 0;
	tmp_a = a;
	while (tmp_a->value != min_e)
		tmp_a = tmp_a->next;
	while (tmp_a->value < tmp_b->value)
	{
		count++;
		tmp_a = tmp_a->next;
	}
	tmp_b->score_a = -count + 1;
}

void	count_score_a_minus_full(t_list *a, t_list *tmp_b, int min_e)
{
	t_list	*tmp_a;
	int		count;

	count = 0;
	tmp_a = a;
	while (tmp_a->value != min_e)
		tmp_a = tmp_a->next;
	while (tmp_a->value < tmp_b->value)
		tmp_a = tmp_a->next;
	while (tmp_a)
	{
		count++;
		tmp_a = tmp_a->next;
	}
	tmp_b->score_a = -count;
}

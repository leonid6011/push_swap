/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:58:42 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/06 12:59:40 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	help_sort(t_list *tmp, int max_element, int type, t_list *head)
{
	tmp = tmp->next;
	if (max_element == tmp->value)
	{
		if (type == 0)
			rra(head);
		else
			rrb(head);
		return ;
	}
	if (type == 0)
		sa(head);
	else
		sb(head);
}

static void	help_sort_three_elem_2(t_list *head, int type)
{
	if (type == 0)
		ra(head);
	else
		rb(head);
}

void	sort_three_elem(t_list *head, int type)
{
	int		max_element;
	int		min_element;
	t_list	*tmp;

	if (argc_call(head) == 1)
		return ;
	tmp = head;
	max_element = max_elem(head);
	min_element = min_elem(head);
	while (!sort_check_final(head))
	{
		if (min_element == head ->value)
		{
			if (type == 0)
				rra(head);
			else
				rrb(head);
		}
		else if (max_element == head->value)
			help_sort_three_elem_2(head, type);
		else if (!(max_element == head->value) && !(min_element == head->value))
			help_sort(tmp, max_element, type, head);
	}
}

static void	help_six(t_list *a, t_list *b, int argc)
{
	sort_three_elem(a, 0);
	sort_three_elem(b, 1);
	while (argc_call(a) != argc)
	{
		if (a->value > b->value)
			pa(a, b);
		ra(a);
	}
	while (!sort_check_final(a))
		ra(a);
}

void	sort_six(t_list *a, int argc)
{
	t_list	*b;
	int		i;
	int		max_of_stack;

	i = 1;
	max_of_stack = max_elem(a);
	if (a->value == max_of_stack)
		ra(a);
	b = start(a->value);
	del_first_elem(a);
	write(1, "pb\n", 3);
	while (i != argc - 3)
	{
		if (max_of_stack != a->value)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	help_six(a, b, argc);
}

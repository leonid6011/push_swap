/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:15:10 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/06 13:33:41 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *head)
{
	t_list	*tmp;
	int		data_one;
	int		data_two;

	if (head == NULL || head -> next == NULL)
		return ;
	tmp = head;
	data_one = tmp->value;
	tmp = tmp->next;
	data_two = tmp->value;
	tmp->value = data_one;
	head->value = data_two;
	write(1, "sa\n", 3);
}

void	sb(t_list *head)
{
	t_list	*tmp;
	int		data_one;
	int		data_two;

	if (head == NULL || head -> next == NULL)
		return ;
	tmp = head;
	data_one = tmp->value;
	tmp = tmp->next;
	data_two = tmp->value;
	tmp->value = data_one;
	head->value = data_two;
	write(1, "sb\n", 3);
}

void	ss(t_list *a, t_list *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	pa(t_list *a, t_list *b)
{
	int		data_b;
	int		data_a;
	int		data_b_next;
	t_list	*temp;

	if (b == NULL)
		return ;
	data_a = a->value;
	data_b = b->value;
	a = add_elem_n(data_b, 2, a);
	a->value = data_b;
	a = a->next;
	a->value = data_a;
	if (b->next == NULL)
	{
		remove_list(b);
		write(1, "pa\n", 3);
		return ;
	}
	temp = b;
	temp = temp->next;
	data_b_next = temp->value;
	b->value = data_b_next;
	del_elem(temp, b);
	write(1, "pa\n", 3);
}

void	pb(t_list *a, t_list *b)
{
	int		data_a;
	int		data_b;
	int		data_a_next;
	t_list	*temp;

	if (a == NULL)
		return ;
	data_b = b->value;
	data_a = a->value;
	b = add_elem_n(data_a, 2, b);
	b->value = data_a;
	b = b->next;
	b->value = data_b;
	if (a->next == NULL)
	{
		remove_list(a);
		write(1, "pb\n", 3);
		return ;
	}
	temp = a;
	temp = temp->next;
	data_a_next = temp->value;
	a->value = data_a_next;
	del_elem(temp, a);
	write(1, "pb\n", 3);
}

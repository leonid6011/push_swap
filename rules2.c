/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:15:29 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/06 13:15:31 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list *a)
{
	t_list	*tmp;
	int		data_elem;
	int		data_del;

	if (a == NULL || a->next == NULL)
		return ;
	data_elem = a->value;
	tmp = a;
	tmp = tmp -> next;
	data_del = tmp->value;
	a = del_elem(tmp, a);
	add_elem_end(data_elem, a);
	a->value = data_del;
	write(1, "ra\n", 3);
}

void	rb(t_list *b)
{
	t_list	*tmp;
	int		data_elem;
	int		data_del;

	if (b == NULL || b->next == NULL)
		return ;
	data_elem = b->value;
	tmp = b;
	tmp = tmp -> next;
	data_del = tmp->value;
	b = del_elem(tmp, b);
	add_elem_end(data_elem, b);
	b->value = data_del;
	write(1, "rb\n", 3);
}

void	rr(t_list *a, t_list *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}

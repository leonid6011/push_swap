/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:15:43 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/06 13:15:45 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list *a)
{
	int		data_elem_first;
	int		data_elem_last;
	t_list	*tmp;

	if (a == NULL || a ->next == NULL)
		return ;
	data_elem_first = a ->value;
	a = add_elem_n(data_elem_first, 2, a);
	tmp = a;
	while (tmp ->next != NULL)
		tmp = tmp ->next;
	data_elem_last = tmp ->value;
	a ->value = data_elem_last;
	a = del_elem(tmp, a);
	write(1, "rra\n", 4);
}

void	rrb(t_list *b)
{
	int		data_elem_first;
	int		data_elem_last;
	t_list	*tmp;

	if (b == NULL || b->next == NULL)
		return ;
	data_elem_first = b ->value;
	b = add_elem_n(data_elem_first, 2, b);
	tmp = b;
	while (tmp ->next != NULL)
		tmp = tmp ->next;
	data_elem_last = tmp ->value;
	b ->value = data_elem_last;
	b = del_elem(tmp, b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list *a, t_list *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}

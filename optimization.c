/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:37:30 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/11 17:37:44 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	list_count(t_list *a, int min_elem_stack)
{
	int	count;

	count = 0;
	while (a->value != min_elem_stack)
	{
		count++;
		a = a->next;
	}
	return (count);
}

void	rra_and_ra(t_list *a, int argc, int min_elem_stack)
{
	int	count;

	count = list_count(a, min_elem_stack);
	argc = argc / 2;
	if (argc > count)
		ra(a);
	else
		rra(a);
}

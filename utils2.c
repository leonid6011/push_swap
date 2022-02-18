/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:20:09 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/06 13:20:34 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_list(t_list *head)
{
	t_list	*p;

	while (head != NULL)
	{
		p = head;
		head = head->next;
		free (p);
	}
}

t_list	*del_elem(t_list *del, t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp->next != del)
		tmp = tmp->next;
	tmp->next = del->next;
	free (del);
	return (tmp);
}

void	del_first_elem(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	tmp = tmp->next;
	head->value = tmp->value;
	head = del_elem(tmp, head);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:16:47 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/06 13:18:19 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*start(int data)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	tmp->value = data;
	tmp->next = NULL;
	return (tmp);
}

t_list	*add_elem(int data, t_list *head)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	tmp->value = data;
	tmp->next = head;
	return (tmp);
}

void	add_elem_end(int data, t_list *head)
{
	t_list	*tmp;
	t_list	*p;

	tmp = (t_list *)malloc(sizeof(t_list));
	tmp->value = data;
	tmp->next = NULL;
	p = head;
	while (p->next != NULL)
		p = p->next;
	p->next = tmp;
}

t_list	*add_elem_n(int data, int n, t_list *head)
{
	t_list	*p;
	t_list	*tmp;
	int		count;

	p = head;
	count = 1;
	while (count < n - 1 && p -> next != NULL)
	{
		p = p->next;
		count++;
	}
	tmp = (t_list *)malloc(sizeof(t_list));
	tmp->value = data;
	tmp->next = p->next;
	p->next = tmp;
	return (head);
}

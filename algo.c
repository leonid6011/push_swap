/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:56:25 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/06 12:58:26 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_elem(t_list *head)
{
	int	max_elem;

	max_elem = -2147483648;
	while (head->next != NULL)
	{
		if (max_elem < head->value)
			max_elem = head->value;
		head = head->next;
	}
	if (max_elem < head ->value)
	max_elem = head ->value;
	return (max_elem);
}

int	min_elem(t_list *head)
{
	int	min_elem;

	min_elem = 2147483647;
	while (head ->next != NULL)
	{
		if (min_elem > head ->value)
			min_elem = head ->value;
		head = head -> next;
	}
	if (min_elem > head ->value)
	min_elem = head ->value;
	return (min_elem);
}

int	sort_check_final(t_list *head)
{
	int		result;
	t_list	*prev;

	prev = head;
	result = 1;
	if (!head->next)
		exit(0);
	head = head->next;
	while (head->next)
	{
		if (head->value < prev->value)
			result = 0;
		head = head->next;
		prev = prev->next;
	}
	if (head->value < prev->value)
		result = 0;
	return (result);
}

int	argc_call(t_list *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head -> next;
	}
	return (i);
}

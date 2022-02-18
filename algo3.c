/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:25:48 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/06 15:25:50 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*list_copy(t_list *head)
{
	t_list	*copy;

	copy = start(head->value);
	head = head->next;
	while (head)
	{
		add_elem_end(head->value, copy);
		head = head->next;
	}
	return (copy);
}

static void	sa_for_sort(t_list *head)
{
	t_list	*tmp;
	int		data_one;
	int		data_two;

	if (head == NULL || head -> next == NULL)
		return ;
	tmp = head;
	data_one = tmp -> value;
	tmp = tmp -> next;
	data_two = tmp -> value;
	tmp -> value = data_one;
	head -> value = data_two;
}

static t_list	*sorted_list_copy(t_list *head)
{
	t_list	*copy;
	t_list	*tmp_left;
	t_list	*tmp_right;
	t_list	*original;

	original = list_copy(head);
	copy = original;
	while (!sort_check_final(original))
	{
		copy = original;
		while (copy->next)
		{
			tmp_left = copy;
			tmp_right = copy;
			tmp_right = tmp_right->next;
			if (tmp_left->value > tmp_right->value && copy->next)
				sa_for_sort(copy);
			copy = copy->next;
		}
	}
	return (original);
}

int	med(t_list *head, int new_argc)
{
	int		med;
	int		*arr;
	int		i;
	t_list	*copy;
	t_list	*copy_to_copy;

	i = 0;
	arr = (int *)malloc(sizeof(int) * new_argc);
	copy = sorted_list_copy(head);
	copy_to_copy = copy;
	while (copy_to_copy)
	{
		arr[i] = copy_to_copy->value;
		copy_to_copy = copy_to_copy->next;
		i++;
	}
	i = i / 2;
	med = arr[i];
	remove_list(copy);
	free(arr);
	return (med);
}

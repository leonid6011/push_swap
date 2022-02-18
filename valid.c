/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:22:15 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/06 13:24:20 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	dup_search(t_list *head)
{
	t_list	*tmp;
	t_list	*tmp_for_del;
	int		data;

	tmp_for_del = head;
	while (head)
	{
		tmp = head;
		data = tmp->value;
		tmp = tmp->next;
		while (tmp)
		{
			if (data == tmp->value)
			{
				remove_list(tmp_for_del);
				error();
			}
			tmp = tmp->next;
		}
		head = head->next;
	}
}

int	find_space(char elem)
{
	int	flag;

	flag = 0;
	if (elem == ' ' || elem == '\t' || elem == '\n'
		|| elem == '\r' || elem == '\v' || elem == '\f')
		flag = 1;
	return (flag);
}

void	valid_argv(char *new_argv)
{
	if (!ft_atoi(new_argv) && new_argv[0] != '0')
		error ();
}

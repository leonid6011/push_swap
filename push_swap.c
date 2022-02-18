/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:11:39 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/06 13:11:43 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_sort_help(t_list *a)
{
	if (sort_check_final(a))
	{
		remove_list(a);
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	int		new_argc;
	t_list	*a;

	if (argc < 2)
		exit (1);
	a = init_list(argv);
	dup_search(a);
	check_sort_help(a);
	new_argc = argc_call(a);
	if (new_argc < 7)
	{
		if (new_argc < 4)
			sort_three_elem(a, 0);
		else
			sort_six(a, new_argc);
	}
	else
		else_sort(a, new_argc);
	remove_list(a);
	return (0);
}

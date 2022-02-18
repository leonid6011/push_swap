/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:24:38 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/06 13:30:19 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct	s_point
{
	int	i;
	int	j;
	int	k;
};

static t_list	*push_to_list(char *argv, t_list *head)
{
	valid_argv(argv);
	add_elem_end(ft_atoi(argv), head);
	return (head);
}

static int	work_with_small_arr(t_list *head, char **argv, struct s_point index)
{
	char	**small_new_arr;
	int		k;

	k = 0;
	small_new_arr = ft_split(argv[index.i], argv[index.i][index.j]);
	while (small_new_arr[k])
	{
		push_to_list(small_new_arr[k], head);
		free(small_new_arr[k]);
		k++;
	}
	free(small_new_arr);
	return (k);
}

t_list	*init_list(char **argv)
{
	t_list			*head;
	int				flag;
	struct s_point	index;

	index.i = 2;
	valid_argv(argv[1]);
	head = start(ft_atoi(argv[1]));
	while (argv[index.i])
	{
		index.j = 0;
		flag = 0;
		while (argv[index.i][index.j])
		{
			if (find_space(argv[index.i][index.j]))
			{
				flag = work_with_small_arr(head, argv, index);
				break ;
			}
			index.j++;
		}
		if (flag == 0)
			push_to_list(argv[index.i], head);
		index.i++;
	}
	return (head);
}

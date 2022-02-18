/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:08:39 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/06 13:08:47 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_score_a(t_list *a, t_list *b, int min_e)
{
	t_list	*tmp_b;
	t_list	*tmp_a_last;

	tmp_b = b;
	tmp_a_last = a;
	while (tmp_a_last->next)
		tmp_a_last = tmp_a_last->next;
	while (tmp_b)
	{
		if (tmp_b->value < a->value && tmp_b->value > tmp_a_last->value)
			count_score_a_plus(a, tmp_b);
		if (tmp_b->value < a->value && tmp_b->value < tmp_a_last->value)
			count_score_a_minus_full(a, tmp_b, min_e);
		if (tmp_b->value > a->value && tmp_b->value < tmp_a_last->value)
			count_score_a_minus(a, tmp_b, min_e);
		if (tmp_b->value > a->value && tmp_b->value > tmp_a_last->value)
			count_score_a_plus(a, tmp_b);
		tmp_b = tmp_b->next;
	}
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		nbr = nbr * (-1);
	return (nbr);
}

void	push_to_a_more(t_list *a, t_list *b, int score_a, int score_b)
{
	if (score_a > 0)
	{
		while (score_a != 0)
		{
			score_a--;
			ra(a);
		}
	}
	if (score_b > 0)
	{
		while (score_b != 0)
		{
			score_b--;
			rb(b);
		}
	}
}

void	push_to_a_less(t_list *a, t_list *b, int score_a, int score_b)
{
	if (score_a < 0)
	{
		while (score_a != 0)
		{
			score_a++;
			rra(a);
		}
	}
	if (score_b < 0)
	{
		while (score_b != 0)
		{
			score_b++;
			rrb(b);
		}
	}
}

void	push_to_a(t_list *a, t_list *b)
{
	int		optimal_score;
	t_list	*tmp_b;
	int		score_b;
	int		score_a;

	tmp_b = b;
	optimal_score = 2147483647;
	while (tmp_b)
	{
		if ((ft_abs(tmp_b->score_a) + ft_abs(tmp_b->score_b)) < optimal_score)
			optimal_score = ft_abs(tmp_b->score_a) + ft_abs(tmp_b->score_b);
		tmp_b = tmp_b->next;
	}
	tmp_b = b;
	while (tmp_b)
	{
		if ((ft_abs(tmp_b->score_a) + ft_abs(tmp_b->score_b)) == optimal_score)
			break ;
		tmp_b = tmp_b->next;
	}
	score_b = tmp_b->score_b;
	score_a = tmp_b->score_a;
	push_to_a_more(a, b, score_a, score_b);
	push_to_a_less(a, b, score_a, score_b);
	pa(a, b);
}

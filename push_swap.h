/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:12:52 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/06 13:35:24 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

typedef struct node
{
	int			value;
	int			score_a;
	int			score_b;
	struct node	*next;
}	t_list;

t_list	*start(int data);
t_list	*add_elem(int data, t_list *head);
void	add_elem_end(int data, t_list *head);
t_list	*add_elem_n(int data, int n, t_list *head);
t_list	*del_elem(t_list *lst, t_list *root);
void	remove_list(t_list *head);
void	del_first_elem(t_list *head);

void	error(void);
char	**ft_split(char const *s, char c);
void	valid_argv(char *new_argv);
int		find_space(char elem);

t_list	*init_list(char **new_argv);
void	dup_search(t_list *head);
void	sort_check(t_list *head, int argc);
int		sort_check_final(t_list *head);
int		argc_call(t_list *head);

void	sort_six(t_list *a, int argc);
void	sort_three_elem(t_list *head, int type);

void	else_sort(t_list *a, int new_argc);
t_list	*init_b_first_push(t_list *a, int max_elem_stack, int min_elem_stack);
int		ft_abs(int nbr);
void	count_score_a_minus_full(t_list *a, t_list *tmp_b, int min_e);
void	count_score_a_minus(t_list *a, t_list *tmp_b, int min_e);
void	count_score_a_plus(t_list *a, t_list *tmp_b);
void	count_score_a(t_list *a, t_list *b, int min_e);
void	count_score_b(t_list *b);
void	push_to_a(t_list *a, t_list *b);

int		ft_atoi(const char *str);

void	sa(t_list *head);
void	sb(t_list *head);
void	ss(t_list *a, t_list *b);

void	pa(t_list *a, t_list *b);
void	pb(t_list *a, t_list *b);
void	ra(t_list *a);
void	rb(t_list *b);
void	rr(t_list *a, t_list *b);

void	rra(t_list *a);
void	rrb(t_list *b);
void	rrr(t_list *a, t_list *b);

int		max_elem(t_list *head);
int		min_elem(t_list *head);
int		med(t_list *head, int new_argc);

void	rra_and_ra(t_list *a, int argc, int min_elem_stack);
char	*mem(const char *s, size_t n);

#endif

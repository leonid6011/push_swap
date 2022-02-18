/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:10:14 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/06 13:10:21 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	nbr_of_wrd(char const *s, char c)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			nbr++;
		while (s[i] != '\0' && (s[i] != c))
			i++;
	}
	return (nbr);
}

char	*mem(const char *s, size_t n)
{
	char	*elem_arr;
	size_t	i;

	i = 0;
	elem_arr = (char *)malloc(sizeof(char) * n + 1);
	if (elem_arr == NULL)
		return (NULL);
	while (s[i] != '\0' && i != n)
	{
		elem_arr[i] = s[i];
		i++;
	}
	elem_arr[n] = '\0';
	return (elem_arr);
}

static char	**free_str(char **result)
{
	size_t	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	result = NULL;
	return (0);
}

static char	**split_help(char **result, const char *s, int m, char c)
{
	int	k;
	int	n;

	k = 0;
	n = 0;
	while (s[m])
	{
		while (s[m] == c)
			m++;
		n = m;
		while (s[m] && s[m] != c)
			m++;
		if (m > n)
		{
			result[k] = mem(&s[n], m - n);
			if (result[k] == NULL)
			{
				result = free_str(result);
				return (result);
			}
			k++;
		}
	}
	result[k] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		m;

	m = 0;
	if (!s)
		return (NULL);
	result = (char **)malloc((sizeof(char *) * ((nbr_of_wrd(s, c)) + 1)));
	if (result == NULL)
		return (0);
	result = split_help(result, s, m, c);
	return (result);
}

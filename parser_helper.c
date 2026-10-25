/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaga <thaga@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:18:13 by thaga             #+#    #+#             */
/*   Updated: 2026/10/25 16:18:14 by thaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <limits.h>
#include <stddef.h>

int	convert_num(char *elem, int *num)
{
	long	ln;
	long	sign;
	int		i;

	sign = 1;
	ln = 0;
	i = 0;
	if (elem[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (elem[i] == '\0')
		return (ERROR);
	while (elem[i])
	{
		if (!(elem[i] >= '0' && elem[i] <= '9'))
			return (ERROR);
		ln = (ln * 10) + elem[i] - '0';
		if (ln > (long)INT_MAX + (sign == -1))
			return (ERROR);
		i++;
	}
	*num = (int)(ln * sign);
	return (OK);
}

double	calc_disorder(t_data *data)
{
	t_node	*i;
	t_node	*j;
	long	mistakes;
	long	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = data->a.top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

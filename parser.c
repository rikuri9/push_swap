/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaga <thaga@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:16:01 by thaga             #+#    #+#             */
/*   Updated: 2026/10/25 16:16:03 by thaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

static int	duplication_check(t_data *data, int num)
{
	t_node	*cur;

	cur = data->a.top;
	while (cur != NULL)
	{
		if (cur->value == num)
			return (1);
		cur = cur->next;
	}
	return (0);
}

static int	set_data(t_data *data, int num)
{
	t_node	*elem;
	t_node	*cur;

	if (duplication_check(data, num))
		return (ERROR);
	elem = malloc(sizeof(t_node));
	if (elem == NULL)
		return (ERROR);
	elem->value = num;
	elem->next = NULL;
	if (data->a.top == NULL)
	{
		data->a.top = elem;
		return (OK);
	}
	cur = data->a.top;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = elem;
	return (OK);
}

static int	set_index(t_data *data)
{
	t_node	*target;
	t_node	*current;
	int		count;
	int		rank;

	count = 0;
	target = data->a.top;
	while (target != NULL)
	{
		rank = 0;
		current = data->a.top;
		while (current != NULL)
		{
			if (current->value < target->value)
				rank++;
			current = current->next;
		}
		target->index = rank;
		count++;
		target = target->next;
	}
	data->a.size = count;
	if (count == 0)
		return (ERROR);
	return (OK);
}

static int	parse_flag(t_data *data, char *s)
{
	if (ft_strcmp(s, "--bench") == 0)
		data->bench = 1;
	else if (ft_strcmp(s, "--simple") == 0)
		data->start = SIMPLE;
	else if (ft_strcmp(s, "--medium") == 0)
		data->start = MEDIUM;
	else if (ft_strcmp(s, "--complex") == 0)
		data->start = COMPLEX;
	else if (ft_strcmp(s, "--adaptive") == 0)
		data->start = ADAPTIVE;
	else
		return (ERROR);
	return (OK);
}

int	parse_input_data(int argc, char **argv, t_data *data)
{
	int		i;
	int		num;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (parse_flag(data, argv[i]))
				return (ERROR);
		}
		else
		{
			num = 0;
			if (convert_num(argv[i], &num))
				return (ERROR);
			if (set_data(data, num))
				return (ERROR);
		}
		i++;
	}
	if (set_index(data))
		return (NONE_NUM);
	data->disorder = calc_disorder(data);
	return (OK);
}

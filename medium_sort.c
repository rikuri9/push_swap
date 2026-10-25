/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaga <thaga@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:19:10 by thaga             #+#    #+#             */
/*   Updated: 2026/10/25 16:19:11 by thaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	chunk_size(int n)
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}

static void	push_chunks(t_data *data, int chunk)
{
	int	pushed;

	pushed = 0;
	while (data->a.size > 0)
	{
		if (data->a.top->index <= pushed)
		{
			op_exe(data, &pb, 1);
			op_exe(data, &rb, 1);
			pushed++;
		}
		else if (data->a.top->index <= pushed + chunk)
		{
			op_exe(data, &pb, 1);
			pushed++;
		}
		else
			op_exe(data, &ra, 1);
	}
}

static void	pull_back(t_data *data)
{
	int	size;
	int	idx;

	while (data->b.size > 0)
	{
		size = data->b.size;
		idx = find_idx(&data->b, size - 1);
		if (idx <= size - idx)
			op_exe(data, &rb, idx);
		else
			op_exe(data, &rrb, size - idx);
		op_exe(data, &pa, 1);
	}
}

void	medium_sort(t_data *data)
{
	push_chunks(data, chunk_size(data->a.size));
	pull_back(data);
}

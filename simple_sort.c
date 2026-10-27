/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:15:57 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/27 17:55:01 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bring_to_top(t_data *data, int idx)
{
	int	size;

	size = data->a.size;
	if (idx <= size - idx)
		op_exe(data, &ra, idx);
	else
		op_exe(data, &rra, size - idx);
}

void	simple_sort(t_data *data)
{
	int	i;
	int	n;

	i = 0;
	n = data->a.size;
	while (i < n)
	{
		bring_to_top(data, find_idx(&data->a, i));
		op_exe(data, &pb, 1);
		i++;
	}
	op_exe(data, &pa, n);
}

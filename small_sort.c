/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:50:05 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/28 17:13:37 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_data *data)
{
	int		cur_max;

	cur_max = find_idx(&data->a, data->a.size - 1);
	if (cur_max == 0)
		op_exe(data, &ra, 1);
	if (cur_max == 1)
		op_exe(data, &rra, 1);
	if (data->a.top->index > data->a.top->next->index)
		op_exe(data, &sa, 1);
}

void	small_sort(t_data *data)
{
	int	i;
	int	n;

	i = 0;
	n = data->a.size;
	while (i < n - 3)
	{
		bring_to_top(data, find_idx(&data->a, i));
		op_exe(data, &pb, 1);
		i++;
	}
	sort_three(data);
	op_exe(data, &pa, data->b.size);
}

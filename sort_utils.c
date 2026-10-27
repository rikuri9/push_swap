/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:16:01 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/27 17:46:24 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	op_exe(t_data *data, void (*f)(t_data *data), int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		f(data);
		i++;
	}
}

int	find_idx(t_stack *s, int target)
{
	t_node	*cur;
	int		idx;

	cur = s->top;
	idx = 0;
	while (cur != NULL)
	{
		if (cur->index == target)
			return (idx);
		idx++;
		cur = cur->next;
	}
	return (-1);
}

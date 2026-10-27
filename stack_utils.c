/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:16:07 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/27 18:24:49 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_node_exe(t_node *top)
{
	t_node	*cur;
	t_node	*tmp;

	cur = top;
	while (cur != NULL)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
}

void	free_node_all(t_data *data)
{
	free_node_exe(data->a.top);
	free_node_exe(data->b.top);
}

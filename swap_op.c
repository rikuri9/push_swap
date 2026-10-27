/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:14:43 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/27 17:28:48 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *s)
{
	t_node	*tmp;

	if (s->size < 2)
		return ;
	tmp = s->top->next->next;
	s->top->next->next = s->top;
	s->top = s->top->next;
	s->top->next->next = tmp;
}

void	sa(t_data *data)
{
	swap(&data->a);
	data->counts[SA]++;
	ft_putendl_fd("sa", 1);
}

void	sb(t_data *data)
{
	swap(&data->b);
	data->counts[SB]++;
	ft_putendl_fd("sb", 1);
}

void	ss(t_data *data)
{
	swap(&data->a);
	swap(&data->b);
	data->counts[SS]++;
	ft_putendl_fd("ss", 1);
}

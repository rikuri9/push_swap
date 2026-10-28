/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:15:08 by thaga             #+#    #+#             */
/*   Updated: 2026/10/28 16:01:14 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	rev_rotate(t_stack *stack)
{
	t_node	*tmp;
	t_node	*cur;

	if (stack->size < 2)
		return ;
	cur = stack->top;
	while (cur->next->next != NULL)
		cur = cur->next;
	tmp = cur->next;
	cur->next = NULL;
	tmp->next = stack->top;
	stack->top = tmp;
}

void	rra(t_data *data)
{
	rev_rotate(&data->a);
	data->counts[RRA]++;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_data *data)
{
	rev_rotate(&data->b);
	data->counts[RRB]++;
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_data *data)
{
	rev_rotate(&data->a);
	rev_rotate(&data->b);
	data->counts[RRR]++;
	ft_putendl_fd("rrr", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaga <thaga@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:14:33 by thaga             #+#    #+#             */
/*   Updated: 2026/10/25 16:14:36 by thaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft.h"

static void	rotate(t_stack	*stack)
{
	t_node	*tmp;
	t_node	*cur;

	if (stack->size < 2)
		return ;
	tmp = stack->top;
	stack->top = stack->top->next;
	tmp->next = NULL;
	cur = stack->top;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = tmp;
}

void	ra(t_data *data)
{
	rotate(&data->a);
	data->counts[RA]++;
	ft_putendl_fd("ra", 1);
}

void	rb(t_data *data)
{
	rotate(&data->b);
	data->counts[RB]++;
	ft_putendl_fd("rb", 1);
}

void	rr(t_data *data)
{
	rotate(&data->a);
	rotate(&data->b);
	data->counts[RR]++;
	ft_putendl_fd("rr", 1);
}

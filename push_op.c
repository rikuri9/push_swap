/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:15:52 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/27 17:37:58 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	push(t_stack *take, t_stack *put)
{
	t_node	*tmp;

	if (take->size == 0)
		return ;
	tmp = take->top->next;
	take->top->next = put->top;
	put->top = take->top;
	take->top = tmp;
	take->size--;
	put->size++;
}

void	pa(t_data *data)
{
	push(&data->b, &data->a);
	data->counts[PA]++;
	ft_putendl_fd("pa", 1);
}

void	pb(t_data *data)
{
	push(&data->a, &data->b);
	data->counts[PB]++;
	ft_putendl_fd("pb", 1);
}

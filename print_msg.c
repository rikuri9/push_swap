/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:17:21 by thaga             #+#    #+#             */
/*   Updated: 2026/10/28 16:01:30 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	print_error(void)
{
	ft_putendl_fd("Error", 2);
	return (1);
}

static void	print_disorder(double d)
{
	int	num;

	num = (int)(d * 10000 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(num / 100, 2);
	ft_putstr_fd(".", 2);
	if (num % 100 < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(num % 100, 2);
	ft_putstr_fd("%\n", 2);
}

static int	total_ops(t_data *data)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < OP_COUNT)
	{
		total += data->counts[i];
		i++;
	}
	return (total);
}

static void	print_op(char *op_type, int count)
{
	ft_putstr_fd(op_type, 2);
	ft_putnbr_fd(count, 2);
}

void	print_bench(t_data *data)
{
	print_disorder(data->disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(data->used_name, 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(total_ops(data), 2);
	ft_putstr_fd("\n[bench] ", 2);
	print_op("sa: ", data->counts[SA]);
	print_op(" sb: ", data->counts[SB]);
	print_op(" ss: ", data->counts[SS]);
	print_op(" pa: ", data->counts[PA]);
	print_op(" pb: ", data->counts[PB]);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ", 2);
	print_op("ra: ", data->counts[RA]);
	print_op(" rb: ", data->counts[RB]);
	print_op(" rr: ", data->counts[RR]);
	print_op(" rra: ", data->counts[RRA]);
	print_op(" rrb: ", data->counts[RRB]);
	print_op(" rrr: ", data->counts[RRR]);
	ft_putstr_fd("\n", 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 15:16:55 by thaga             #+#    #+#             */
/*   Updated: 2026/10/28 16:01:50 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	data_init(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->start = ADAPTIVE;
}

static void	start_sort(t_data *data, void (*f)(t_data *data),
						char *sort_type_name)
{
	data->used_name = sort_type_name;
	if (data->disorder == 0)
		return ;
	f(data);
}

static void	adaptive_sort(t_data *data)
{
	if (data->a.size <= 5)
		start_sort(data, &small_sort, "Adaptive / O(1)");
	else if (data->disorder < 0.2)
		start_sort(data, &simple_sort, "Adaptive / O(n²)");
	else if (data->disorder < 0.5)
		start_sort(data, &medium_sort, "Adaptive / O(n√n)");
	else
		start_sort(data, &complex_sort, "Adaptive / O(n log n)");
}

int	main(int argc, char **argv)
{
	t_data			data;
	t_error_type	err_type;

	data_init(&data);
	err_type = parse_input_data(argc, argv, &data);
	if (err_type == NONE_NUM)
		return (0);
	if (err_type == ERROR)
	{
		free_node_all(&data);
		return (print_error());
	}
	if (data.start == SIMPLE)
		start_sort(&data, &simple_sort, "Simple / O(n²)");
	else if (data.start == MEDIUM)
		start_sort(&data, &medium_sort, "Medium / O(n√n)");
	else if (data.start == COMPLEX)
		start_sort(&data, &complex_sort, "Complex / O(n log n)");
	else
		adaptive_sort(&data);
	if (data.bench)
		print_bench(&data);
	free_node_all(&data);
	return (0);
}

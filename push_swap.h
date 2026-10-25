/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaga <thaga@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 15:14:51 by thaga             #+#    #+#             */
/*   Updated: 2026/10/25 15:14:54 by thaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef enum e_error_type
{
	OK,
	ERROR,
	NONE_NUM
}	t_error_type;

typedef enum e_start
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_start;

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_COUNT
}	t_op;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node		*top;
	int			size;
}	t_stack;

typedef struct s_data
{
	t_stack		a;
	t_stack		b;
	int			counts[OP_COUNT];
	t_start		start;
	int			bench;
	double		disorder;
	char		*used_name;
}	t_data;

/* parser.c */
int		parse_input_data(int argc, char **argv, t_data *data);

/* parser_helper.c */
double	calc_disorder(t_data *data);
int		convert_num(char *elem, int *num);
int		ft_strcmp(char *s1, char *s2);

/* print_msg.c */
void	print_bench(t_data *data);
int		print_error(void);

/* stack_utils.c */
void	free_node_all(t_data *data);

/* swap_op.c */
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);

/* push_op.c */
void	pa(t_data *data);
void	pb(t_data *data);

/* rotate_op.c */
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);

/* rev_rotate_op.c */
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

/* sort_utils.c */
void	op_exe(t_data *data, void (*f)(t_data *data), int cnt);
int		find_idx(t_stack *s, int target);

/* simple_sort.c */
void	simple_sort(t_data *data);

/* medium_sort.c */
void	medium_sort(t_data *data);

/* complex_sort.c */
void	complex_sort(t_data *data);

#endif

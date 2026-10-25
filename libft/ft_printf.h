/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaga <thaga@student.42tokyo.jp>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-12 05:18:20 by thaga             #+#    #+#             */
/*   Updated: 2026-10-12 05:18:20 by thaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *format, ...);
int	print_char(int c);
int	print_str(char *s);
int	print_pointer(void *p);
int	print_hex(unsigned int num);
int	print_hex_upper(unsigned int num);
int	print_decimal(int num);
int	print_unsigned_int(unsigned int num);

#endif
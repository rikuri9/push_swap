/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaga <thaga@student.42tokyo.jp>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-17 00:54:25 by thaga             #+#    #+#             */
/*   Updated: 2026-10-17 00:54:25 by thaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

char	*get_next_line(int fd);
size_t	gnl_is_lf_check(char *s);
char	*gnl_free_and_null(char **elem);
char	*gnl_strjoin_free_s1(char *s1, char *s2);
char	*gnl_save_cut_and_update(char **save);

#endif

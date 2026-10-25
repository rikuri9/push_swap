/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaga <thaga@student.42tokyo.jp>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-17 00:54:29 by thaga             #+#    #+#             */
/*   Updated: 2026-10-17 00:54:29 by thaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	ssize_t		ret;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (buf == NULL)
		return (gnl_free_and_null(&save));
	while (save == NULL || !gnl_is_lf_check(save))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (gnl_free_and_null(&save), gnl_free_and_null(&buf));
		buf[ret] = '\0';
		save = gnl_strjoin_free_s1(save, buf);
		if (ret == 0 || save == NULL || save[0] == '\0')
			break ;
	}
	gnl_free_and_null(&buf);
	if (save == NULL || save[0] == '\0')
		return (gnl_free_and_null(&save));
	return (gnl_save_cut_and_update(&save));
}

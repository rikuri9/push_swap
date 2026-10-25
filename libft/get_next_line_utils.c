/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaga <thaga@student.42tokyo.jp>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-17 00:54:32 by thaga             #+#    #+#             */
/*   Updated: 2026-10-17 00:54:32 by thaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdlib.h>

static size_t	gnl_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	gnl_is_lf_check(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*gnl_free_and_null(char **elem)
{
	free(*elem);
	*elem = NULL;
	return (NULL);
}

char	*gnl_strjoin_free_s1(char *s1, char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	if (s2_len == 0)
		return (s1);
	result = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result == NULL)
		return (free(s1), NULL);
	i = 0;
	while (i < s1_len + s2_len)
	{
		if (i < s1_len)
			result[i] = s1[i];
		else
			result[i] = s2[i - s1_len];
		i++;
	}
	free(s1);
	result[i] = '\0';
	return (result);
}

char	*gnl_save_cut_and_update(char **save)
{
	char	*result;
	char	*update;
	size_t	save_len;
	size_t	sep_len;
	size_t	i;

	save_len = gnl_strlen(*save);
	sep_len = gnl_is_lf_check(*save);
	if (sep_len == 0)
		sep_len = save_len;
	result = malloc(sizeof(char) * (sep_len + 1));
	if (result == NULL)
		return (gnl_free_and_null(save));
	i = -1;
	while (++i < sep_len)
		result[i] = (*save)[i];
	result[i] = '\0';
	update = malloc(sizeof(char) * (save_len - sep_len + 1));
	if (update == NULL)
		return (free(result), gnl_free_and_null(save));
	while (i++ <= save_len)
		update[i - sep_len - 1] = (*save)[i - 1];
	free(*save);
	*save = update;
	return (result);
}

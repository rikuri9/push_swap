/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaga <thaga@student.42tokyo.jp>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-09 01:58:05 by thaga             #+#    #+#             */
/*   Updated: 2026-10-09 01:58:05 by thaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static size_t	get_word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*get_word(char const *s, char c)
{
	char	*word;
	size_t	size;
	size_t	i;

	size = 0;
	while (s[size] && s[size] != c)
		size++;
	word = malloc(sizeof(char) * (size + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**all_free(char **result, size_t idx)
{
	size_t	i;

	i = 0;
	while (i < idx)
	{
		free(result[i]);
		result[i] = NULL;
		i++;
	}
	free(result);
	result = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	idx;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (get_word_count(s, c) + 1));
	if (result == NULL)
		return (NULL);
	idx = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			result[idx] = get_word(s, c);
			if (result[idx] == NULL)
				return (all_free(result, idx));
			idx++;
		}
		while (*s && *s != c)
			s++;
	}
	result[idx] = NULL;
	return (result);
}

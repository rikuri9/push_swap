/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaga <thaga@student.42tokyo.jp>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-08 05:00:50 by thaga             #+#    #+#             */
/*   Updated: 2026-10-08 05:00:50 by thaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	int		i;

	result = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			result = (char *)&s[i];
		i++;
	}
	if ((char) c == '\0')
		return ((char *) &s[i]);
	return (result);
}

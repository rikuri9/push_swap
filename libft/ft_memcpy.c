/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaga <thaga@student.42tokyo.jp>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-08 02:45:37 by thaga             #+#    #+#             */
/*   Updated: 2026-10-08 02:45:37 by thaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_p;
	const unsigned char	*src_p;
	size_t				i;

	dest_p = (unsigned char *)dest;
	src_p = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_p[i] = (unsigned char) src_p[i];
		i++;
	}
	return (dest);
}

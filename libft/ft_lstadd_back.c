/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaga <thaga@student.42tokyo.jp>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-09 04:24:54 by thaga             #+#    #+#             */
/*   Updated: 2026-10-09 04:24:54 by thaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cur;

	if (!new || !lst)
		return ;
	cur = *lst;
	if (cur == NULL)
	{
		*lst = new;
		return ;
	}
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

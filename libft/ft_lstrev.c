/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 10:52:20 by rsharipo          #+#    #+#             */
/*   Updated: 2018/07/26 14:39:58 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **lst)
{
	t_list	*cur;
	t_list	*next;
	t_list	*prev;

	prev = NULL;
	if (lst && *lst)
	{
		cur = *lst;
		while (cur != 0)
		{
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		*lst = prev;
	}
}

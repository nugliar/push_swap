/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 11:13:18 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/04 10:02:27 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **lst, void const *cont, size_t size)
{
	t_list *tmp;

	tmp = NULL;
	if (!lst)
		return ;
	if (!(*lst))
	{
		*lst = ft_lstnew(cont, size);
		return ;
	}
	if (!(tmp = ft_lstnew(cont, size)))
		return ;
	tmp->next = *lst;
	*lst = tmp;
}

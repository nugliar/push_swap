/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:04:23 by rsharipo          #+#    #+#             */
/*   Updated: 2018/07/13 16:23:43 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	**lst;

	tmp = NULL;
	lst = alst;
	if (alst && *alst)
	{
		tmp = *alst;
		while (tmp)
		{
			tmp = tmp->next;
			ft_lstdelone(lst, del);
			*lst = tmp;
		}
		alst = NULL;
	}
}

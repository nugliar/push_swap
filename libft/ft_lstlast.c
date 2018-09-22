/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 10:48:19 by rsharipo          #+#    #+#             */
/*   Updated: 2018/07/14 10:51:26 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *tmp;

	if (lst)
	{
		tmp = lst;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		return (tmp);
	}
	return (NULL);
}

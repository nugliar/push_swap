/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 10:58:25 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/04 10:01:52 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_lstpop(t_list **lst)
{
	t_list	*tmp;
	void	*ret;

	ret = NULL;
	if (lst && *lst)
	{
		if ((ret = malloc((*lst)->size)))
			ft_memcpy(ret, (*lst)->cont, (*lst)->size);
		tmp = (*lst)->next;
		free((*lst)->cont);
		(*lst)->cont = NULL;
		(*lst)->size = 0;
		free(*lst);
		*lst = tmp;
		return (ret);
	}
	return (NULL);
}

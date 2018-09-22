/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:35:41 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/04 10:32:29 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *cont, size_t size)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new)
	{
		new->cont = NULL;
		if (cont && (new->cont = malloc(size)))
			ft_memcpy(new->cont, cont, size);
		new->size = (cont) ? size : 0;
		new->next = NULL;
		return (new);
	}
	else
		return (NULL);
}

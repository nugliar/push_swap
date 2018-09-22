/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 09:07:51 by rsharipo          #+#    #+#             */
/*   Updated: 2018/07/12 17:39:18 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	if ((ptr = (unsigned char *)malloc(size)))
	{
		while (i < size)
			ptr[i++] = 0;
		return ((void *)ptr);
	}
	else
		return (NULL);
}

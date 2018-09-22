/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:59:13 by rsharipo          #+#    #+#             */
/*   Updated: 2018/07/10 14:48:18 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int	i;
	char*p;

	i = 0;
	if ((p = (char *)malloc(ft_strlen(s1) + 1)))
	{
		while (s1[i] != '\0')
		{
			p[i] = s1[i];
			i++;
		}
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}

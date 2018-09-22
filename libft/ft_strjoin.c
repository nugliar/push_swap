/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 10:33:59 by rsharipo          #+#    #+#             */
/*   Updated: 2018/07/12 15:34:03 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 && s2 && (str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		*str = 0;
		str = ft_strcat(str, s1);
		str = ft_strcat(str, s2);
		return (str);
	}
	return (NULL);
}

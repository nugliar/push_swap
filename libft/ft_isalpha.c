/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 21:04:16 by rsharipo          #+#    #+#             */
/*   Updated: 2018/07/12 13:00:41 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	unsigned int	x;

	x = (unsigned int)c;
	if ((x >= 65 && x <= 90) || (x >= 97 && x <= 122))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 10:55:30 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/11 10:57:29 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		space_needed(int value, int base)
{
	int	len;

	len = 0;
	while (value)
	{
		len++;
		value = value / base;
	}
	return (len);
}

int		*create_arr(int value, int base, int len)
{
	int	*arr;

	arr = NULL;
	arr = (int *)malloc(sizeof(int) * len);
	while (arr && value)
	{
		arr[len-- - 1] = (value < 0) ? (-1 * (value % base)) : (value % base);
		value = value / base;
	}
	return (arr);
}

char	*create_str(int *arr, int len, int neg)
{
	char*s;
	int	i;

	s = NULL;
	i = 0;
	if (!(s = (char *)malloc(len + neg + 1)))
		return (0);
	if (neg)
		s[0] = '-';
	while (i < len)
	{
		if (arr[i] >= 0 && arr[i] <= 9)
			s[i + neg] = arr[i] + 48;
		else if (arr[i] >= 10 && arr[i] <= 15)
			s[i + neg] = arr[i] + 55;
		i++;
	}
	s[i + neg] = 0;
	return (s);
}

char	*ft_itoa_base(int value, int base)
{
	int	neg;
	int len;
	int	*arr;
	char*s;

	s = NULL;
	arr = NULL;
	len = 0;
	neg = 0;
	if (value == 0)
		return ("0");
	if (base != 10 && value < 0)
		value = -value;
	else if (value < 0)
		neg = 1;
	len = space_needed(value, base);
	arr = create_arr(value, base, len);
	s = create_str(arr, len, neg);
	return (s);
}

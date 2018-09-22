/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 11:16:09 by rsharipo          #+#    #+#             */
/*   Updated: 2018/09/03 16:49:28 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int	ft_calc(char const *s, char c)
{
	unsigned int	i;
	unsigned int	num;

	i = 0;
	num = 0;
	if (s)
	{
		while (s[i] == c && s[i] != 0)
			i++;
		while (s[i] != 0)
		{
			num++;
			while (s[i] != c && s[i] != 0)
				i++;
			while (s[i] == c && s[i] != 0)
				i++;
		}
	}
	return (num);
}

char				**ft_clean(char **arr, unsigned int words)
{
	unsigned int	i;

	i = -1;
	while (arr && ++i <= words)
		(*arr) ? free(arr[i]) : 0;
	free(arr);
	return (NULL);
}

char				**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	start;
	unsigned int	words;
	char			**arr;

	i = 0;
	j = 0;
	start = 0;
	words = ft_calc(s, c);
	if (!s || !(arr = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (j < words)
	{
		while (s[i] == c && s[i] != 0)
			i++;
		start = i;
		while (s[i] != c && s[i] != 0)
			i++;
		if (!(arr[j++] = ft_strsub(s, start, (size_t)(i - start))))
			arr = ft_clean(arr, words);
	}
	(arr) ? (arr[j] = 0) : 0;
	return (arr);
}

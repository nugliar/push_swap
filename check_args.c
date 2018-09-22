/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 09:46:17 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/26 14:50:20 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		check_dup(t_list *l, int num)
{
	while (l)
	{
		if (l->num == num)
			return (0);
		l = l->next;
	}
	return (1);
}

int		is_num(char *s)
{
	int			i;

	i = 0;
	while (is_space(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!ft_isdigit(s[i]))
		return (0);
	while (ft_isdigit(s[i]))
		i++;
	while (is_space(s[i]))
		i++;
	if (s[i])
		return (0);
	return (1);
}

int		get_nbr(t_data *data, char **s, int len)
{
	long long	num;

	num = 0;
	len--;
	while (len >= 0)
	{
		if (!is_num(s[len]))
			return (0);
		num = ft_atoi(s[len]);
		if (num < INT_MIN || num > INT_MAX
				|| !check_dup(*(data->a), num))
			return (0);
		l_push(data, (int)num, 1);
		len--;
	}
	return (1);
}

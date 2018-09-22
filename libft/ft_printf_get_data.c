/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 09:49:49 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/11 11:26:54 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(char c, char *flag)
{
	char	check;

	check = *flag;
	if (ft_strchr("#0 -+'", c))
	{
		(c == '#') ? (check |= SHARP) : 0;
		(c == '0') ? (check |= ZERO) : 0;
		(c == '-') ? (check |= MINUS) : 0;
		(c == '+') ? (check |= PLUS) : 0;
		(c == 32) ? (check |= SPACE) : 0;
		(c == 39) ? (check |= APOS) : 0;
		*flag |= check;
		return (1);
	}
	return (0);
}

int		is_len(char c, char next, char *len, int *i)
{
	char	check;

	check = 0;
	if (!ft_strchr("hljz", c))
		return (0);
	if (c == 'h' && next == 'h' && (*i += 1))
		check |= HH;
	else if (c == 'h')
		check |= H;
	if (c == 'l' && next == 'l' && (*i += 1))
		check |= LL;
	else if (c == 'l')
		check |= L;
	(c == 'j') ? check |= J : 0;
	(c == 'z') ? check |= Z : 0;
	if (check > *len)
		*len = check;
	return (1);
}

void	get_data(t_arg *data, const char *s, int *i)
{
	if (s[*i] == 0)
		return ;
	if (is_flag(s[*i], &(data->flag)))
		*i += 1;
	else if (s[*i] >= '0' && s[*i] <= '9')
	{
		data->fwid = ft_atoi(s + *i);
		while (s[*i] && s[*i] >= '0' && s[*i] <= '9')
			*i += 1;
	}
	else if (s[*i] == '.' && (*i += 1))
	{
		data->flag |= PREC;
		data->prec = ft_atoi(s + *i);
		while (s[*i] && s[*i] >= '0' && s[*i] <= '9')
			*i += 1;
	}
	else if (s[*i] && is_len(s[*i], s[*i + 1], &(data->len), i))
		*i += 1;
	else
	{
		data->type = s[*i];
		return ;
	}
	get_data(data, s, i);
}

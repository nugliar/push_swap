/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_else.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 09:54:06 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/11 10:29:46 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_else(t_arg *data, char flag, size_t i)
{
	char	*s;

	if (data->fwid > 1)
		data->str_size = data->fwid;
	else
		data->str_size = 1;
	data->space = data->fwid - 1;
	if (!(s = (char *)malloc(data->str_size + 1)))
		return ;
	if (!(flag & MINUS))
		oper(data, s, &i, (flag & ZERO) ? ('0') : (' '));
	s[i++] = data->type;
	if (flag & MINUS)
		oper(data, s, &i, (' '));
	s[i] = 0;
	pr_str(data, s, i);
	free(s);
}

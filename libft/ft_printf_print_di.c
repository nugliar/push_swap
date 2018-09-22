/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_di.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 09:48:54 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/11 11:07:47 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	di_to_s(t_arg *data, char *s, intmax_t n, size_t *i)
{
	int			j;

	j = data->size;
	while (--j >= 0)
	{
		if (n < 0)
			s[*i + j] = -1 * (n % data->base) + 48;
		else
			s[*i + j] = n % data->base + 48;
		n = n / data->base;
	}
	*i += data->size;
}

void	di_str_size(t_arg *data, intmax_t n, size_t size)
{
	if ((int)size > data->prec)
		data->str_size += size;
	else
		data->str_size += (size_t)data->prec;
	if (n < 0 || data->flag & SPACE || data->flag & PLUS)
		data->str_size += 1;
	data->space = data->fwid - (int)(data->str_size);
	if (data->str_size < (size_t)data->fwid)
		data->str_size = (size_t)data->fwid;
}

void	di_size(t_arg *data, intmax_t n)
{
	if (n == 0 && data->prec == 0)
		data->size = 0;
	else if (n == 0)
		data->size = 1;
	while (n)
	{
		data->size += 1;
		n = n / (intmax_t)(data->base);
	}
}

void	print_di(t_arg *data, intmax_t n, char flag, size_t i)
{
	char	*s;

	di_size(data, n);
	di_str_size(data, n, data->size);
	if (!(s = (char *)malloc(data->str_size + 1)))
		return ;
	if (flag & ZERO)
		oper(data, s, &i, (n < 0) ? ('-') : ('+'));
	if (!(flag & MINUS))
		oper(data, s, &i, (flag & ZERO) ? ('0') : (' '));
	if (!(flag & ZERO))
		oper(data, s, &i, (n < 0) ? ('-') : ('+'));
	oper(data, s, &i, ('p'));
	di_to_s(data, s, n, &i);
	if (flag & MINUS)
		oper(data, s, &i, (' '));
	s[i] = 0;
	pr_str(data, s, i);
	free(s);
}

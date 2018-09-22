/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_len.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 19:14:46 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/11 09:38:35 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_di(t_arg *data, char len, va_list *arg)
{
	char		type;
	intmax_t	val;

	val = 0;
	type = data->type;
	if (!(data->flag & PREC))
		data->prec = 1;
	if (!len)
		val = (int)va_arg(*arg, int);
	else if (len & HH)
		val = (signed char)va_arg(*arg, int);
	else if (len & H)
		val = (short)va_arg(*arg, int);
	else if (len & LL)
		val = (long long)va_arg(*arg, long long);
	else if (len & L)
		val = (long)va_arg(*arg, long);
	else if (len & J)
		val = va_arg(*arg, intmax_t);
	else if (len & Z)
		val = (size_t)va_arg(*arg, size_t);
	print_di(data, val, data->flag, 0);
}

void	format_oux(t_arg *data, char len, va_list *arg)
{
	char		type;
	uintmax_t	val;

	val = 0;
	type = data->type;
	if (!len)
		val = (unsigned int)va_arg(*arg, unsigned int);
	else if (len & HH)
		val = (unsigned char)va_arg(*arg, unsigned int);
	else if (len & H)
		val = (unsigned short)va_arg(*arg, unsigned int);
	else if (len & LL)
		val = (unsigned long long)va_arg(*arg, unsigned long long);
	else if (len & L)
		val = (unsigned long)va_arg(*arg, unsigned long);
	else if (len & J)
		val = va_arg(*arg, uintmax_t);
	else if (len & Z)
		val = (size_t)va_arg(*arg, size_t);
	print_oux(data, val, data->flag, 0);
}

void	format_c(t_arg *data, char len, va_list *arg)
{
	unsigned int	wc;
	char			c;

	wc = 0;
	c = 0;
	if (len & L)
	{
		wc = va_arg(*arg, unsigned int);
		print_wc(data, wc);
	}
	else
	{
		c = (char)va_arg(*arg, int);
		print_c(data, &c, 1);
	}
}

void	format_s(t_arg *data, char len, va_list *arg)
{
	unsigned int	*ws;
	char			*s;

	s = NULL;
	ws = NULL;
	if (len & L)
		ws = va_arg(*arg, unsigned int *);
	else
		s = va_arg(*arg, char *);
	if (!s && !ws && !(data->flag & PREC))
	{
		if (!(data->flag & PREC))
			pr_str(data, "(null)", 6);
		return ;
	}
	if (len & L)
		print_ws(data, ws);
	else
		print_s(data, s, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:04:23 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/24 10:11:19 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags(char *len, char *flag, char *type)
{
	if (ft_strchr("DOUCS", *type) && (*len = L))
		*type += 32;
	if (!(*type == 'x' || *type == 'X' || *type == 'o'))
		*flag &= (~SHARP);
	if (*type == 'p')
	{
		*flag = (*flag & (~SPACE) & (~PLUS) & (~PREC)) | SHARP;
		*len = L;
	}
	if (ft_strchr("diouxXp", *type) && (*flag & MINUS || *flag & PREC))
		*flag &= (~ZERO);
	if (!(*type == 'd' || *type == 'i'))
	{
		*flag &= (~SPACE);
		*flag &= (~PLUS);
	}
	if (*flag & PLUS)
		*flag &= (~SPACE);
}

void	format(t_arg *data, va_list *arg)
{
	flags(&(data->len), &(data->flag), &(data->type));
	if (data->type == 'x' || data->type == 'X' || data->type == 'p')
		data->base = 16;
	else if (data->type == 'o')
		data->base = 8;
	if (data->type == 1)
		pr_str(data, "%", 1);
	else if (ft_strchr("id", data->type))
		format_di(data, data->len, arg);
	else if (ft_strchr("ouxXp", data->type))
		format_oux(data, data->len, arg);
	else if (data->type == 's')
		format_s(data, data->len, arg);
	else if (data->type == 'c')
		format_c(data, data->len, arg);
	else if (data->type != -1)
		print_else(data, data->flag, 0);
}

void	parse(t_arg *data, const char *s, va_list *arg)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (s[i])
	{
		start = i;
		while (s[i] && s[i] != '%')
			i++;
		if (i > start)
			pr_str(data, s + start, i - start);
		if (s[i] == '%' && s[++i])
		{
			get_data(data, s, &i);
			format(data, arg);
		}
		l_arg_zero(data);
		if (s[i])
			i++;
	}
}

int		ft_printf(const char *format, ...)
{
	int		num;
	va_list	arg;
	t_arg	*data;

	num = 0;
	va_start(arg, format);
	if (!(data = l_arg_new()))
		return (-1);
	if (format)
		parse(data, format, &arg);
	num = data->num;
	free(data);
	data = NULL;
	return (num);
}

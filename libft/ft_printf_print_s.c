/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_s.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 09:52:14 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/11 10:30:32 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s(t_arg *data, char *src, size_t i)
{
	char	*s;

	data->size = ft_strlen(src);
	if (data->prec < (int)data->size && data->flag & PREC)
		data->size = data->prec;
	data->str_size = data->size;
	data->space = data->fwid - (int)data->str_size;
	if (data->fwid > (int)data->str_size)
		data->str_size = data->fwid;
	if (!(s = (char *)malloc(data->str_size + 1)))
		return ;
	if (!(data->flag & MINUS))
		oper(data, s, &i, (data->flag & ZERO) ? ('0') : (' '));
	if (src)
	{
		ft_memcpy(s + i, src, data->size);
		i += data->size;
	}
	if (data->flag & MINUS)
		oper(data, s, &i, (' '));
	s[i] = 0;
	pr_str(data, s, i);
	free(s);
}

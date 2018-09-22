/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_ws.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 09:53:10 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/11 09:53:56 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ws_len(unsigned int *s)
{
	int len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

void	print_ws(t_arg *data, unsigned int *src)
{
	char *s;

	data->size = ws_len(src);
	if (data->prec < (int)data->size && data->flag & PREC)
		data->size = data->prec;
	s = convert_to_utf_8(src, data->size, data->prec);
	print_s(data, s, 0);
	if (s)
		free(s);
}

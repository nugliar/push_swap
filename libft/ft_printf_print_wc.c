/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_wc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 09:51:33 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/16 09:57:52 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_wc(t_arg *data, unsigned int c)
{
	char	*s;

	s = NULL;
	s = convert_to_utf_8(&c, 1, data->prec);
	print_c(data, s, c ? ft_strlen(s) : 1);
	if (s)
		free(s);
}

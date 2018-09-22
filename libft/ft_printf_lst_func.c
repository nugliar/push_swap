/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lst_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 19:20:09 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/24 10:11:29 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	l_arg_zero(t_arg *l)
{
	if (l)
	{
		l->flag = 0;
		l->len = 0;
		l->fwid = 0;
		l->prec = -1;
		l->type = -1;
		l->size = 0;
		l->str_size = 0;
		l->space = 0;
		l->base = 10;
	}
}

t_arg	*l_arg_new(void)
{
	t_arg	*new;

	new = NULL;
	if (!(new = malloc(sizeof(t_arg))))
		return (NULL);
	new->flag = 0;
	new->len = 0;
	new->fwid = 0;
	new->prec = -1;
	new->type = -1;
	new->num = 0;
	new->size = 0;
	new->str_size = 0;
	new->space = 0;
	new->base = 10;
	return (new);
}

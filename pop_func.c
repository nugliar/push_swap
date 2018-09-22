/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:20:13 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/25 12:20:30 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		l_pop(t_data *data, int sw)
{
	int		res;
	t_list	*tmp;
	t_list	**l;

	res = 0;
	(sw == 1) ? (l = data->a) : 0;
	(sw == 2) ? (l = data->b) : 0;
	(sw == 3) ? (l = &(data->op)) : 0;
	if (!l)
		exit_prog(data, 1);
	if (*l)
	{
		tmp = (*l)->next;
		res = (*l)->num;
		free(*l);
		*l = tmp;
		(sw == 1) ? data->a_count -= 1 : 0;
		(sw == 2) ? data->b_count -= 1 : 0;
		return (res);
	}
	return (INT_MIN);
}

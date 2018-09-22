/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:18:43 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/25 12:19:01 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	l_rot_one(t_list **l)
{
	t_list	*tmp;

	tmp = *l;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = *l;
	tmp = *l;
	*l = (*l)->next;
	tmp->next = NULL;
}

void	l_rot(t_data *data, int sw)
{
	t_list	**l;

	(sw == 1) ? (l = data->a) : 0;
	(sw == 2) ? (l = data->b) : 0;
	if (sw == 3)
	{
		l_rot(data, 1);
		l_rot(data, 2);
		return ;
	}
	if (!l)
		exit_prog(data, 1);
	if (*l && (*l)->next)
	{
		l_rot_one(l);
		(data->verb) ? print_out(ROT, sw) : 0;
	}
}

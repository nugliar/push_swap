/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrot_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:19:11 by rsharipo          #+#    #+#             */
/*   Updated: 2018/09/03 16:37:45 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	l_rrot_one(t_list **l)
{
	t_list	*tmp;
	t_list	*end;

	tmp = *l;
	while (tmp->next->next)
		tmp = tmp->next;
	end = tmp->next;
	tmp->next = NULL;
	end->next = *l;
	*l = end;
}

void	l_rrot(t_data *data, int sw)
{
	t_list	**l;

	(sw == 1) ? (l = data->a) : 0;
	(sw == 2) ? (l = data->b) : 0;
	if (sw == 3)
	{
		l_rrot(data, 1);
		l_rrot(data, 2);
		return ;
	}
	if (!l)
		exit_prog(data, 1);
	if (*l && (*l)->next)
	{
		l_rrot_one(l);
		(data->verb) ? print_out(RROT, sw) : 0;
	}
}

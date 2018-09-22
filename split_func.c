/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:23:47 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/26 12:03:21 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		split_dir(t_list *l, int mid, int num, int sw)
{
	int		count;
	int		rev_count;
	int		i;

	count = 0;
	rev_count = 0;
	i = 0;
	while (i++ < num / 2)
	{
		if ((sw == 1 && l->num <= mid) || (sw == 2 && l->num > mid))
			count++;
		l = l->next;
	}
	while (l)
	{
		if ((sw == 1 && l->num <= mid) || (sw == 2 && l->num > mid))
			rev_count++;
		l = l->next;
	}
	return ((count >= rev_count) ? 1 : 0);
}

void	split_l(t_data *data, int limit, int num, int sw)
{
	t_list	**l;

	l = (sw == 1) ? data->a : data->b;
	if (!(data->a) || !(data->b) || !(*l))
		return ;
	if (!num || data->counter >= (limit / 2 + limit % 2))
		return ;
	if (sw == 1 && (*l)->num <= data->mid)
	{
		l_push(data, l_pop(data, 1), 2);
		data->counter += 1;
	}
	else if (sw == 2 && (*l)->num >= data->mid)
	{
		l_push(data, l_pop(data, 2), 1);
		data->counter += 1;
	}
	else
		l_rot(data, sw);
	split_l(data, limit, num - 1, sw);
}

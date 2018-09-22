/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 18:09:50 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/26 12:08:02 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		is_next(t_list *l, int cur, int prev, int sw)
{
	if (cur == find_cur(l, prev, sw))
		return (1);
	return (0);
}

void	final_sort(t_data *data, t_list **b)
{
	int		cur;
	int		dir;
	int		found;

	find_min_max(data, *b);
	cur = data->max;
	while (b && (*b))
	{
		found = 0;
		dir = find_dir(*b, cur);
		while ((*b)->num != cur)
		{
			if (!found && is_next(*b, (*b)->num, cur, 2))
			{
				l_push(data, l_pop(data, 2), 1);
				found = 1;
			}
			else
				(dir) ? l_rot(data, 2) : l_rrot(data, 2);
		}
		l_push(data, l_pop(data, 2), 1);
		(to_swap(data, 1)) ? swap(data, 1) : 0;
		cur = find_cur(*b, cur, 2);
	}
}

void	sort_l(t_data *data)
{
	int	i;

	find_min_max(data, *(data->a));
	find_mid(data, *(data->a));
	split_l(data, data->a_count, data->a_count, 1);
	i = 0;
	while (i++ < CYCLES)
	{
		data->counter = 0;
		find_min_max(data, *(data->b));
		find_mid(data, *(data->b));
		split_l(data, data->b_count, data->b_count, 2);
	}
	i = 0;
	while (i++ < CYCLES + 4)
	{
		data->counter = 0;
		find_min_max(data, *(data->a));
		find_mid(data, *(data->a));
		split_l(data, data->a_count, data->a_count, 1);
	}
	while (*(data->a))
		l_push(data, l_pop(data, 1), 2);
	final_sort(data, data->b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 19:53:22 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/26 16:22:56 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		next_num(t_data *data, t_list *l, int sw)
{
	while (l && l->next)
	{
		if (sw == 1 && l->num > l->next->num
				&& !(l->num == data->max && l->next->num == data->min))
			break ;
		if (sw == 1 && l->num > l->next->num
				&& !(l->num == data->max && l->next->num == data->min))
			break ;
		l = l->next;
	}
	return (l->num);
}

void	sort_one(t_data *data, t_list **l, int sw)
{
	int		cur;
	int		dir;

	find_min_max(data, *l);
	cur = (sw == 1) ? INT_MIN : INT_MAX;
	while (!shift_sorted(*l, sw))
	{
		cur = next_num(data, *l, sw);
		dir = find_dir(*l, cur);
		if (to_swap(data, sw))
			swap(data, sw);
		else
			(dir) ? l_rot(data, sw) : l_rrot(data, sw);
	}
	dir = find_dir(*l, ((sw == 1) ? data->min : data->max));
	while ((*l)->num != ((sw == 1) ? data->min : data->max))
		(dir) ? l_rot(data, sw) : l_rrot(data, sw);
}

void	sort_two(t_data *data, t_list **l, int sw)
{
	int		cur;
	int		dir;
	int		rev_sw;
	int		found;

	rev_sw = ((sw == 1) ? 2 : 1);
	find_min_max(data, *l);
	cur = (sw == 1) ? data->min : data->max;
	while (*l)
	{
		found = 0;
		dir = find_dir(*l, cur);
		while ((*l)->num != cur)
		{
			if (!found && is_next(*l, (*l)->num, cur, sw) && (++found))
				l_push(data, l_pop(data, sw), rev_sw);
			else
				(dir) ? l_rot(data, sw) : l_rrot(data, sw);
		}
		l_push(data, l_pop(data, sw), rev_sw);
		(to_swap(data, rev_sw)) ? swap(data, rev_sw) : 0;
		cur = find_cur(*l, cur, sw);
	}
}

void	sort_small(t_data *data)
{
	if (!(data->a) || !(data->b))
		exit_prog(data, 1);
	if (data->a_count == 1 || sorted(*(data->a), 1))
		return ;
	if (data->a_count <= 2)
	{
		if (to_swap(data, 1))
			swap(data, 1);
	}
	else if (shift_sorted(*data->a, 1) || data->a_count <= 4)
		sort_one(data, data->a, 1);
	else if (data->a_count <= 10)
	{
		find_min_max(data, *(data->a));
		find_mid(data, *(data->a));
		split_l(data, data->a_count, data->a_count, 1);
		sort_one(data, data->a, 1);
		sort_two(data, data->b, 2);
	}
	else
	{
		sort_two(data, data->a, 1);
		while (*(data->b))
			l_push(data, l_pop(data, 2), 1);
	}
}

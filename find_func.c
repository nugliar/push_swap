/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:28:18 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/25 12:58:08 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		find_cur(t_list *l, long cur, int sw)
{
	int	prev;

	prev = (sw == 1) ? INT_MAX : INT_MIN;
	while (l)
	{
		if (sw == 1 && l->num > cur && l->num <= prev)
			prev = l->num;
		else if (sw == 2 && l->num < cur && l->num >= prev)
			prev = l->num;
		l = l->next;
	}
	return (prev);
}

int		find_dir(t_list *l, int cur)
{
	int	len;

	len = 0;
	while (l)
	{
		len++;
		if (l->num == cur)
			break ;
		l = l->next;
	}
	if (len <= l_size(l))
		return (1);
	else
		return (0);
}

void	find_min_max(t_data *data, t_list *l)
{
	data->min = INT_MAX;
	data->max = INT_MIN;
	while (l)
	{
		if (l->num > data->max)
			data->max = l->num;
		if (l->num < data->min)
			data->min = l->num;
		l = l->next;
	}
}

void	correct_mid(t_data *data, t_list *l)
{
	int		left;
	int		right;
	int		diff;
	t_list	*beg;
	int		odd;

	beg = l;
	diff = INT_MAX;
	odd = (l_size(l) % 2) ? 1 : 0;
	while (diff < 0 - odd || diff > 0 + odd)
	{
		right = 0;
		left = 0;
		while (l)
		{
			(l->num > data->mid) ? right++ : left++;
			l = l->next;
		}
		l = beg;
		diff = right - left;
		(diff > 0 + odd) ? data->mid += 1 : 0;
		(diff < 0 - odd) ? data->mid -= 1 : 0;
	}
}

void	find_mid(t_data *data, t_list *l)
{
	find_min_max(data, l);
	data->mid = (data->max - data->min) / 2;
	correct_mid(data, l);
}

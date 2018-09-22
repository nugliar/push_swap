/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:20:31 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/25 16:32:08 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*l_new(t_data *data, int num)
{
	t_list	*new;

	new = NULL;
	if ((new = malloc(sizeof(t_list))))
	{
		new->next = NULL;
		new->num = num;
	}
	else
		exit_prog(data, 2);
	return (new);
}

void	l_rev(t_list **l)
{
	t_list	*cur;
	t_list	*next;
	t_list	*prev;

	prev = NULL;
	if (l && *l)
	{
		cur = *l;
		while (cur)
		{
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		*l = prev;
	}
}

int		l_size(t_list *l)
{
	int	len;

	len = 0;
	while (l)
	{
		len++;
		l = l->next;
	}
	return (len);
}

int		sorted(t_list *l, int sw)
{
	while (l && l->next)
	{
		if (sw == 1 && l->num > l->next->num)
			return (0);
		else if (sw == 2 && l->num < l->next->num)
			return (0);
		l = l->next;
	}
	return (1);
}

int		shift_sorted(t_list *l, int sw)
{
	t_list	*beg;
	int		check;

	beg = l;
	check = 0;
	while (l && l->next)
	{
		if (sw == 1 && l->num > l->next->num)
			check++;
		else if (sw == 2 && l->num < l->next->num)
			check++;
		l = l->next;
	}
	if (sw == 1 && l->num > beg->num)
		check++;
	else if (sw == 2 && l->num < beg->num)
		check++;
	if (check < 2)
		return (1);
	return (0);
}

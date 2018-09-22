/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:16:14 by rsharipo          #+#    #+#             */
/*   Updated: 2018/09/03 16:38:09 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>

void	swap_one(t_list **l)
{
	t_list	*tmp;

	tmp = (*l)->next;
	(*l)->next = (*l)->next->next;
	tmp->next = *l;
	*l = tmp;
}

void	swap(t_data *data, int sw)
{
	t_list	**l;

	(sw == 1) ? (l = data->a) : 0;
	(sw == 2) ? (l = data->b) : 0;
	if (sw == 3)
	{
		swap(data, 1);
		swap(data, 2);
		return ;
	}
	if (!l)
		exit_prog(data, 1);
	if (*l && (*l)->next)
	{
		swap_one(l);
		(data->verb) ? print_out(SWAP, sw) : 0;
	}
}

int		to_swap(t_data *data, int sw)
{
	t_list	**l;
	int		one;
	int		two;
	int		len;

	(sw == 1) ? (l = data->a) : 0;
	(sw == 2) ? (l = data->b) : 0;
	if (sw == 3 && to_swap(data, 1) && to_swap(data, 2))
		return (1);
	if (!l)
		exit_prog(data, 1);
	if (*l && (*l)->next)
	{
		one = (*l)->num;
		two = (*l)->next->num;
		len = l_size(*l);
		if (sw == 1 && one > two
				&& !(len > 2 && one == data->max && two == data->min))
			return (1);
		else if (sw == 2 && one < two
				&& !(len > 2 && one == data->min && two == data->max))
			return (1);
	}
	return (0);
}

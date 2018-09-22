/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:17:56 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/25 12:18:34 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	l_push(t_data *data, int num, int sw)
{
	t_list	**l;
	t_list	*new;

	new = NULL;
	(sw == 1) ? (l = data->a) : 0;
	(sw == 2) ? (l = data->b) : 0;
	(sw == 3) ? (l = &(data->op)) : 0;
	if (!l)
		exit_prog(data, 1);
	if (!(new = l_new(data, num)))
		exit_prog(data, 2);
	new->next = *l;
	*l = new;
	(sw == 1) ? data->a_count += 1 : 0;
	(sw == 2) ? data->b_count += 1 : 0;
	(data->verb) ? print_out(PUSH, sw) : 0;
}

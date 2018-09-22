/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 18:04:37 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/23 18:08:40 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_data(t_data *data, t_list **a, t_list **b, int ac)
{
	data->a = a;
	data->b = b;
	*(data->a) = NULL;
	*(data->b) = NULL;
	data->op = NULL;
	data->op_dis = NULL;
	data->count = ac - 1;
	data->a_count = 0;
	data->b_count = 0;
	data->counter = 0;
	data->min = 0;
	data->max = 0;
	data->verb = 0;
	data->mid = 0;
}

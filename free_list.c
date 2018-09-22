/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 19:37:52 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/25 13:28:05 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_list(t_data *data)
{
	while (data->a && *(data->a))
		l_pop(data, 1);
	while (data->b && *(data->b))
		l_pop(data, 2);
	if (data->op_dis)
		free(data->op_dis);
}

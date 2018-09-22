/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 11:09:40 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/25 13:27:42 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	create_disp(t_data *data)
{
	static t_disp dis[] = {
		{ "pa", NULL, &l_push, 1 },
		{ "pb", NULL, &l_push, 2 },
		{ "sa", &swap, NULL, 1 },
		{ "sb", &swap, NULL, 2 },
		{ "ss", &swap, NULL, 3 },
		{ "ra", &l_rot, NULL, 1 },
		{ "rb", &l_rot, NULL, 2 },
		{ "rr", &l_rot, NULL, 3 },
		{ "rra", &l_rrot, NULL, 1 },
		{ "rrb", &l_rrot, NULL, 2 },
		{ "rrr", &l_rrot, NULL, 3 }
	};

	data->op_dis = malloc(sizeof(dis));
	ft_memcpy(data->op_dis, dis, sizeof(dis));
}

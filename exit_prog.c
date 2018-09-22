/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:36:05 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/23 19:42:17 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	exit_prog(t_data *data, int sw)
{
	if (sw == 1)
		ft_printf("ERROR: Unexpected null pointer\n");
	else if (sw == 2)
		ft_printf("ERROR: Malloc failure\n");
	free_list(data);
	if (data)
		free(data);
	exit(0);
}

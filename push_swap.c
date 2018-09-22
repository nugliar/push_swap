/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 19:19:20 by rsharipo          #+#    #+#             */
/*   Updated: 2018/09/03 15:50:06 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_input(t_data *data, char **av, int ac)
{
	int	ret;

	if (ac == 2)
		ret = split_args(data, av[1]);
	else
		ret = get_nbr(data, av + 1, ac - 1);
	return (ret);
}

int		main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_data	*data;

	if (!(data = malloc(sizeof(t_data))))
		exit_prog(data, 2);
	if (ac > 1)
	{
		init_data(data, &a, &b, ac);
		if (check_input(data, av, ac))
		{
			data->verb = 1;
			if (data->a_count <= 20)
				sort_small(data);
			else
				sort_l(data);
		}
		else
			write(2, "Error\n", 6);
		free_list(data);
	}
	free(data);
	return (0);
}

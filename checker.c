/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 16:38:50 by rsharipo          #+#    #+#             */
/*   Updated: 2018/09/03 15:50:47 by rsharipo         ###   ########.fr       */
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
	t_data	*data;
	t_list	*a;
	t_list	*b;

	if (!(data = malloc(sizeof(t_data))))
		exit_prog(data, 2);
	if (ac > 1)
	{
		init_data(data, &a, &b, ac);
		create_disp(data);
		if (check_input(data, av, ac) && read_op(data))
		{
			if (use_ops(data, &(data->op), (t_disp *)(data->op_dis)))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
		else
			write(2, "Error\n", 6);
		free_list(data);
	}
	free(data);
	return (0);
}

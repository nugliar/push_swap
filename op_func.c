/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:39:51 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/26 15:53:16 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		split_args(t_data *data, char *s)
{
	int		len;
	int		ret;
	char	**args;

	ret = 1;
	args = ft_strsplit(s, ' ');
	if (args)
	{
		len = 0;
		while (args[len])
			len++;
		ret = get_nbr(data, args, len);
		while (len-- && args[len])
			free(args[len]);
		free(args);
	}
	return (ret);
}

int		get_op(t_data *data, t_disp *op_dis, char *buf)
{
	char	*s;
	int		len;
	int		i;

	s = "pa/pb/sa/sb/ss/ra/rb/rr/rra/rrb/rrr";
	len = ft_strlen(buf);
	if (!(len >= 2 && len <= 3))
		return (0);
	if (!ft_strstr(s, buf))
		return (0);
	i = 0;
	while (i < SIZE)
	{
		if (!ft_strcmp((const char *)(op_dis[i].key), buf))
		{
			l_push(data, i, 3);
			return (1);
		}
		i++;
	}
	return (0);
}

int		read_op(t_data *data)
{
	int		i;
	int		ret;
	char	**buf;

	buf = (char **)malloc(sizeof(char *));
	if (!buf)
		return (0);
	i = 0;
	*buf = NULL;
	while ((ret = get_next_line(0, buf)) > 0)
	{
		if (!get_op(data, data->op_dis, *buf))
			break ;
		(*buf) ? free(*buf) : 0;
	}
	(*buf) ? free(*buf) : 0;
	(buf) ? free(buf) : 0;
	if (ret != 0)
		return (0);
	return (1);
}

int		use_ops(t_data *data, t_list **op, t_disp *op_dis)
{
	int		num;
	int		sw;

	l_rev(op);
	while (op && *op)
	{
		sw = (op_dis[(*op)->num]).sw;
		if ((op_dis[(*op)->num]).func != NULL)
			((op_dis[l_pop(data, 3)]).func)(data, sw);
		else
		{
			num = (sw == 1) ? l_pop(data, 2) : l_pop(data, 1);
			((op_dis[l_pop(data, 3)]).func_2)(data, num, sw);
		}
	}
	if (*(data->b))
		return (0);
	if (sorted(*(data->a), 1))
		return (1);
	return (0);
}

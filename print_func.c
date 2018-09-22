/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 10:20:34 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/25 13:00:05 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_l_one(t_list *l)
{
	while (l)
	{
		ft_printf("%d ", l->num);
		l = l->next;
	}
	ft_printf("\n");
}

void	print_l(t_list **a, t_list **b)
{
	ft_printf("A[%d] = ", l_size(*a));
	if (a && *a)
		print_l_one(*a);
	else
		ft_printf("NULL\n");
	ft_printf("B[%d] = ", l_size(*b));
	if (b && *b)
		print_l_one(*b);
	else
		ft_printf("NULL\n");
}

void	print_out(int op, int sw)
{
	if (op == PUSH)
	{
		(sw == 1) ? write(1, "pa\n", 3) : 0;
		(sw == 2) ? write(1, "pb\n", 3) : 0;
	}
	else if (op == ROT)
	{
		(sw == 1) ? write(1, "ra\n", 3) : 0;
		(sw == 2) ? write(1, "rb\n", 3) : 0;
	}
	else if (op == RROT)
	{
		(sw == 1) ? write(1, "rra\n", 4) : 0;
		(sw == 2) ? write(1, "rrb\n", 4) : 0;
	}
	else if (op == SWAP)
	{
		(sw == 1) ? write(1, "sa\n", 3) : 0;
		(sw == 2) ? write(1, "sb\n", 3) : 0;
	}
}

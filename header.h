/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:18:20 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/26 15:52:24 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <inttypes.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define SIZE	11
# define CYCLES	2

typedef struct		s_data
{
	struct s_list	**a;
	struct s_list	**b;
	struct s_list	*op;
	void			*op_dis;
	int				count;
	int				a_count;
	int				b_count;
	int				counter;
	int				min;
	int				max;
	int				verb;
	intmax_t		mid;
}					t_data;

typedef struct		s_list
{
	struct s_list	*next;
	int				num;
}					t_list;

typedef struct		s_disp
{
	const char		*key;
	void			(*func)(t_data *, int);
	void			(*func_2)(t_data *, int, int);
	int				sw;
}					t_disp;

typedef enum		e_op
{
	PUSH = (1 << 0),
	SWAP = (1 << 1),
	ROT = (1 << 2),
	RROT = (1 << 3),
}					t_op;

void				exit_prog(t_data *data, int sw);
void				print_out(int flag, int sw);
int					ft_printf(const char *format, ...);
int					ft_isdigit(char c);
void				*ft_memcpy(void *dst, const void *src, size_t size);
int					get_next_line(int fd, char **line);
int					ft_strcmp(const char *s1, char *s2);
char				*ft_strstr(char *s1, char *s2);
char				**ft_strsplit(char const *s, char c);
size_t				ft_strlen(char *s);
void				ft_bzero(void *p, size_t size);
long long			ft_atoi(const char *s);
t_list				*l_new(t_data *data, int num);
void				l_rev(t_list **l);
int					l_pop(t_data *data, int sw);
void				l_push(t_data *data, int num, int sw);
void				l_rot(t_data *data, int sw);
void				l_rot_one(t_list **l);
void				l_rrot(t_data *data, int sw);
void				l_rrot_one(t_list **l);
int					l_size(t_list *l);
void				swap(t_data *data, int sw);
void				swap_one(t_list **l);
int					to_swap(t_data *data, int sw);
int					is_next(t_list *l, int cur, int prev, int sw);
int					pre_sorted(t_list *l, int sw);
int					sorted(t_list *l, int sw);
int					shift_sorted(t_list *l, int sw);
void				sort_small(t_data *data);
void				find_min_max(t_data *data, t_list *l);
int					find_cur(t_list *l, long cur, int sw);
void				find_mid(t_data *data, t_list *l);
int					find_dir(t_list *l, int cur);
void				sort_l(t_data *data);
void				final_sort(t_data *data, t_list **b);
void				split_l(t_data *data, int limit, int num, int sw);
void				print_l(t_list **a, t_list **b);
void				free_list(t_data *data);
void				init_data(t_data *data, t_list **a, t_list **b, int ac);
int					get_op(t_data *data, t_disp *op_dis, char *buf);
int					split_args(t_data *data, char *s);
int					read_op(t_data *data);
int					use_ops(t_data *data, t_list **op, t_disp *op_dis);
void				create_disp(t_data *data);
int					get_nbr(t_data *data, char **s, int len);

#endif

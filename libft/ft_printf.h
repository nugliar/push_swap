/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 17:05:02 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/24 10:11:49 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <inttypes.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <locale.h>

typedef struct	s_arg
{
	char		flag;
	char		len;
	int			fwid;
	int			prec;
	char		type;
	int			num;
	size_t		size;
	size_t		str_size;
	int			space;
	int			base;
}				t_arg;

typedef enum	e_flag
{
	PREC = (1 << 6),
	SHARP = (1 << 5),
	ZERO = (1 << 4),
	MINUS = (1 << 3),
	PLUS = (1 << 2),
	SPACE = (1 << 1),
	APOS = (1 << 0)
}				t_flag;

typedef enum	e_len
{
	Z = (1 << 5),
	J = (1 << 4),
	LL = (1 << 3),
	L = (1 << 2),
	H = (1 << 1),
	HH = (1 << 0)
}				t_len;

int				ft_printf(const char *format, ...);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dst, const char *src);
void			*ft_memcpy(void *dst, const void *src, size_t size);
void			*ft_memset(void *s, int c, size_t n);
int				ft_atoi(const char *str);
t_arg			*l_arg_new(void);
void			l_arg_zero(t_arg *data);
void			pr_str(t_arg *data, const char *s, int size);
void			get_data(t_arg *data, const char *s, int *i);
void			format_di(t_arg *data, char len, va_list *arg);
void			format_oux(t_arg *data, char len, va_list *arg);
void			format_s(t_arg *data, char len, va_list *arg);
void			format_c(t_arg *data, char len, va_list *arg);
void			print_di(t_arg *data, intmax_t n, char flag, size_t i);
void			print_oux(t_arg *data, uintmax_t n, char flag, size_t i);
void			print_c(t_arg *data, char *c, size_t size);
void			print_wc(t_arg *data, unsigned int c);
void			print_s(t_arg *data, char *src, size_t i);
void			print_ws(t_arg *data, unsigned int *src);
void			print_else(t_arg *data, char flag, size_t i);
void			oper(t_arg *data, char *s, size_t *i, char op);
char			*convert_to_utf_8(unsigned int *ws, int size, int prec);

#endif

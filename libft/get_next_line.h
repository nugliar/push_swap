/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 10:29:10 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/21 17:37:45 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE	128
# include <sys/types.h>

typedef struct		s_fd
{
	int				fd;
	struct s_list	*cont;
	struct s_fd		*next;
}					t_fd;

int					get_next_line(const int fd, char **line);
void				find_line(t_list **lst, char *buf, int fd, int *ret);
int					make_str(t_fd **lst, t_fd **link, char **s);

#endif

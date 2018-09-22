/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 10:28:43 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/24 20:49:03 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

int		total_len(t_list *lst)
{
	int		add;
	int		len;
	char	*s;

	add = 0;
	len = 0;
	if (lst)
	{
		while (lst->next)
		{
			len = len + (int)(lst->size) - 1;
			lst = lst->next;
		}
		s = (char *)(lst->cont);
		while (s[add] != 0 && s[add] != '\n')
			add++;
	}
	return (len + add);
}

int		keep_str(t_fd **fd_lst, t_list **lst, char *add)
{
	t_fd	*prev_fd;
	t_fd	*cur_fd;

	cur_fd = *fd_lst;
	prev_fd = *fd_lst;
	if (add == NULL)
	{
		while (cur_fd && (void *)(cur_fd) != (void *)(*lst))
		{
			prev_fd = cur_fd;
			cur_fd = cur_fd->next;
		}
		if (cur_fd)
		{
			prev_fd->next = cur_fd->next;
			free(cur_fd);
		}
		return (0);
	}
	(*add == '\n') ? (add += 1) : 0;
	if (*add != 0)
		*lst = ft_lstnew(add, ft_strlen(add) + 1);
	return (1);
}

int		make_str(t_fd **fd_lst, t_fd **cur_fd, char **s)
{
	int		i;
	char	*add;
	t_list	**lst;

	i = 0;
	add = NULL;
	lst = &((*cur_fd)->cont);
	*s = (char *)malloc(total_len(*lst) + 1);
	(*s)[0] = 0;
	while (*lst)
	{
		(add != NULL) ? free(add) : 0;
		add = (char *)(ft_lstpop(lst));
		i = 0;
		while (add[i] != '\n' && add[i] != 0)
			i++;
		ft_strncat(*s, add, i);
	}
	(keep_str(fd_lst, lst, add + i)) ? 0 : (*cur_fd = NULL);
	free(add);
	add = NULL;
	return ((*cur_fd != NULL) ? 1 : 0);
}

void	find_line(t_list **lst, char *buf, int fd, int *ret)
{
	int		i;
	t_list	**end;

	i = BUFF_SIZE;
	if ((*lst) && ft_strstr((char *)((*lst)->cont), "\n"))
		return ;
	end = (*lst) ? &((*lst)->next) : lst;
	while (i == BUFF_SIZE && (*ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[*ret] = 0;
		i = 0;
		while (buf[i] != 0 && buf[i] != '\n')
			i++;
		*end = ft_lstnew(buf, ft_strlen(buf) + 1);
		end = &((*end)->next);
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_fd		*fd_lst;
	t_fd			*cur_fd;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	cur_fd = fd_lst;
	if (line == NULL || fd < 0)
		return (-1);
	while (cur_fd && (fd != cur_fd->fd))
		cur_fd = cur_fd->next;
	if (cur_fd == NULL)
	{
		if (!(cur_fd = (t_fd *)malloc(sizeof(t_fd))))
			return (-1);
		cur_fd->fd = fd;
		cur_fd->next = fd_lst;
		cur_fd->cont = NULL;
		fd_lst = cur_fd;
	}
	find_line(&(cur_fd->cont), buf, fd, &ret);
	if (ret < 0)
		return (-1);
	if (!(make_str(&fd_lst, &cur_fd, line)) && ret == 0)
		return (0);
	return (1);
}

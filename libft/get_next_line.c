/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 19:42:59 by pzubar            #+#    #+#             */
/*   Updated: 2017/12/17 19:43:01 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"

#define JOIN ft_strcat(arr, buf)

void			*ft_realloc(char *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (ft_strnew(size));
	if (!size)
		return (ptr);
	new_ptr = ft_strnew(ft_strlen(ptr) + size);
	ft_strcpy(new_ptr, ptr);
	ft_strdel(&ptr);
	return (new_ptr);
}

static t_list	*ft_mulfd(t_list **temp, int fd)
{
	t_list *buf;

	buf = *temp;
	while (buf)
	{
		if (fd == (int)buf->content_size)
			return (buf);
		buf = buf->next;
	}
	buf = ft_lstnew("\0", fd);
	ft_lstadd(temp, buf);
	buf = *temp;
	return (buf);
}

int				ft_check(char **buf, void **tmp, char **line, int step)
{
	char	*arr;

	arr = *buf;
	if (arr)
		while (*arr)
			if (*arr++ == '\n')
			{
				*line = ft_strsub(*buf, 0, (ft_strchr(*buf, '\n') - *buf));
				if (*tmp)
					ft_memdel(tmp);
				*tmp = ft_strdup(ft_strchr(*buf, '\n') + 1);
				ft_strdel(buf);
				return (1);
			}
	if (step == 1)
	{
		*line = *buf;
		ft_memdel(tmp);
		return ((!*buf[0]) ? 0 : 1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*arr;
	static t_list	*tmp;
	t_list			*now;
	int				ret;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	now = ft_mulfd(&tmp, fd);
	arr = (now->content) ? ft_strdup(now->content) : NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		(arr = ft_realloc(arr, BUFF_SIZE)) ? JOIN : JOIN;
		if (ft_check(&arr, &(now->content), line, 0))
			return (1);
	}
	if (!arr)
		return (0);
	return (ft_check(&arr, &(now->content), line, 1) ? 1 : 0);
}

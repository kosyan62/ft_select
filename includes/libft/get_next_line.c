/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:46:54 by mgena             #+#    #+#             */
/*   Updated: 2020/03/07 14:53:36 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		write_line(char **to, char *from)
{
	size_t bytes_to_write;

	bytes_to_write = ft_strclen(from, '\n');
	if (!(*to = ft_strnew(bytes_to_write + 2)))
		return (-1);
	ft_strncpy(*to, from, bytes_to_write);
	ft_memmove(from, (&(from[bytes_to_write + 1])),
	ft_strlen(from) - bytes_to_write);
	if (from[bytes_to_write] == 0)
		return (0);
	return (1);
}

int		ft_myjoin(char **buff_fd, const int fd)
{
	int		ret;
	char	*tmp;
	char	buffer[BUFF_SIZE + 1];

	if (!(buff_fd[fd]))
		buff_fd[fd] = ft_strnew(1);
	if (ft_strchr(buff_fd[fd], '\n') != NULL)
		return (1);
	ft_bzero(buffer, BUFF_SIZE + 1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (!(tmp = ft_strjoin(buff_fd[fd], buffer)))
			return (-1);
		ft_strdel(&buff_fd[fd]);
		buff_fd[fd] = tmp;
		if (ft_strchr(buff_fd[fd], '\n') != NULL)
			break ;
		ft_bzero(buffer, BUFF_SIZE + 1);
	}
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*buff_fd[10240];

	if (fd == -1)
	{
		free(*line);
		free(buff_fd[0]);
	}
	if (fd < 0 || line == NULL || fd > 10239 || BUFF_SIZE < 1)
		return (-1);
	ret = ft_myjoin(buff_fd, fd);
	if (ret < 0)
		return (-1);
	if (ret == 0 && buff_fd[fd][0] == 0)
	{
		ft_strdel(&buff_fd[fd]);
		return (0);
	}
	ret = write_line(line, buff_fd[fd]);
	if (ret == 0)
		ft_strdel(&buff_fd[fd]);
	else if (ret == -1)
		return (-1);
	return (1);
}

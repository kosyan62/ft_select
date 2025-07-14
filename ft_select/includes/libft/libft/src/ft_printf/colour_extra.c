/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:13:45 by mgena             #+#    #+#             */
/*   Updated: 2020/03/06 16:13:58 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		set_colour(int fd, char *str)
{
	if (ft_strncmp(str, "{red}", 5) == 0)
		ft_putstr_fd(RED, fd);
	else if (!ft_strncmp(str, "{green}", 7))
		ft_putstr_fd(GRN, fd);
	else if (!ft_strncmp(str, "{yellow}", 8))
		ft_putstr_fd(YEL, fd);
	else if (!ft_strncmp(str, "{blue}", 6))
		ft_putstr_fd(BLU, fd);
	else if (!ft_strncmp(str, "{magnetic}", 10))
		ft_putstr_fd(MAG, fd);
	else if (!ft_strncmp(str, "{cyan}", 6))
		ft_putstr_fd(CYN, fd);
	else if (!ft_strncmp(str, "{white}", 7))
		ft_putstr_fd(WHT, fd);
	else if (!ft_strncmp(str, "{eoc}", 5))
		ft_putstr_fd(RESET, fd);
	else
		exit(0);
}

char		*print_not_percent(int fd, char *str, int *i)
{
	if (*str != '{')
	{
		write(fd, str, 1);
		*i = *i + 1;
		return (str + 1);
	}
	set_colour(fd, str);
	while (*str != '}')
		str++;
	return (str + 1);
}

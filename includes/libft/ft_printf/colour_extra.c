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

void		set_colour(const char *str)
{
	if (ft_strncmp(str, "{red}", 5) == 0)
		ft_putstr(RED);
	else if (!ft_strncmp(str, "{green}", 7))
		ft_putstr(GRN);
	else if (!ft_strncmp(str, "{yellow}", 8))
		ft_putstr(YEL);
	else if (!ft_strncmp(str, "{blue}", 6))
		ft_putstr(BLU);
	else if (!ft_strncmp(str, "{magnetic}", 10))
		ft_putstr(MAG);
	else if (!ft_strncmp(str, "{cyan}", 6))
		ft_putstr(CYN);
	else if (!ft_strncmp(str, "{white}", 7))
		ft_putstr(WHT);
	else if (!ft_strncmp(str, "{eoc}", 5))
		ft_putstr(RESET);
	else
		exit(0);
}

int			print_not_percent(const char *str, int *i)
{
	int len;

	len = 0;
	if (*str != '{')
	{
		write(1, str, 1);
		*i = *i + 1;
		return (1);
	}
	set_colour(str);
	while (*str != '}')
	{
		str++;
		len++;
	}
	return (len + 1);
}

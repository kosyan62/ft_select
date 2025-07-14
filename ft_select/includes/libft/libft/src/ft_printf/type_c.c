/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkingsbl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:09:09 by pkingsbl          #+#    #+#             */
/*   Updated: 2019/12/22 20:41:26 by pkingsbl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_for_char(int fd, va_list ap, t_specif *spec)
{
	char	c;
	int		i;

	i = 1;
	c = (char)va_arg(ap, int);
	if (spec->wide != 0)
	{
		if (spec->minus == 1)
		{
			write(fd, &c, 1);
			while (i++ != spec->wide)
				write(fd, " ", 1);
		}
		else if (spec->minus == 0)
		{
			while (i++ != spec->wide)
				write(fd, " ", 1);
			write(fd, &c, 1);
		}
		return (i - 1);
	}
	write(fd, &c, 1);
	return (1);
}
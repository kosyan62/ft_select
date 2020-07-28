/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:48:13 by mgena             #+#    #+#             */
/*   Updated: 2020/07/28 15:28:55 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct winsize	get_winsize(void)
{
	struct winsize ws;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	return (ws);
}

void 			escape(t_outputs out)
{
	ft_putstr_fd(out.CL, out.fd);
	ft_putstr_fd(out.NORM, out.fd);
	ft_putstr_fd(out.VE, out.fd);
	exit(0);
}

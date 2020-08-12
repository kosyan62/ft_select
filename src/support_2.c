/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 19:55:56 by mgena             #+#    #+#             */
/*   Updated: 2020/08/12 19:58:17 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			escape(t_outputs out)
{
	return_tty(out);
	exit(0);
}

struct winsize	get_winsize(void)
{
	struct winsize ws;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	return (ws);
}

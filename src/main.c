/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:36:36 by mgena             #+#    #+#             */
/*   Updated: 2020/03/16 16:54:48 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

char **select_args(int argc, char **argv)
{
	struct termios tty;
	struct termios savetty;

	if (!(isatty(0)))
	{
		ft_printf("stdin not terminal\n");
		exit(1);
	}
	tcgetattr(0, &tty);
	savetty = tty;
	tty.c_lflag &= ~(ICANON|ECHO|ISIG);
	tty.c_cc[VMIN] = 1;
	tcsetattr(0, TCSAFLUSH, &tty);
	return argv;

}

void do_stuff()
{
	ft_printf()
}

void	ft_select(int argc, char **argv)
{
	char **selections;

	do_stuff()
//	selections = select_args(argc, &argv[2]);
//	execute_command(argv[1], selections);
}

int		main(int argc, char **argv)
{
	if (argc <= 2)
		ft_printf("ft_select: to few arguments");
	else
		ft_select(argc, argv);
}


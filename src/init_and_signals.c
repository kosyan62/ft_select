/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_signals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:11:06 by mgena             #+#    #+#             */
/*   Updated: 2020/08/12 20:13:13 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		init_signals(void)
{
	signal(SIGINT, sighandler);
	signal(SIGABRT, sighandler);
	signal(SIGKILL, sighandler);
	signal(SIGSTOP, sighandler);
	signal(SIGQUIT, sighandler);
	signal(SIGWINCH, sighandler);
	signal(SIGTSTP, sighandler);
	signal(SIGCONT, sighandler);
}

void		sighandler(int sig)
{
	t_outputs out;

	out = out_storage(NULL);
	if (sig == SIGWINCH)
	{
		ft_fdprintf(out.fd, "%s%s", out.HO, out.CL);
		draw_selections();
	}
	else if (sig == SIGINT || sig == SIGABRT || sig == SIGKILL || \
	sig == SIGSTOP || sig == SIGQUIT)
		escape(out);
	else if (sig == SIGTSTP)
	{
		return_tty(out);
		signal(SIGTSTP, SIG_DFL);
		ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
	}
	else if (sig == SIGCONT)
	{
		main_init();
		init_signals();
		draw_selections();
	}
}

t_outputs	main_init(void)
{
	t_outputs		out;
	struct termios	tty;

	out.fd = open(ttyname(STDIN_FILENO), O_RDWR);
	tinit(&out);
	ft_putstr_fd(out.CL, out.fd);
	ft_putstr_fd(out.SC, out.fd);
	ft_putstr_fd(out.VI, out.fd);
	if (!(isatty(0)))
	{
		ft_printf("stdin not terminal\n");
		exit(1);
	}
	tcgetattr(0, &tty);
	out.savetty = tty;
	tty.c_lflag &= ~(ICANON | ECHO);
	tty.c_cc[VMIN] = 1;
	tcsetattr(0, TCSAFLUSH, &tty);
	out_storage(&out);
	return (out);
}

void		return_tty(t_outputs out)
{
	ft_fdprintf(out.fd, "%s%s%s", out.VE, out.HO, out.CD);
	tcsetattr(0, TCSAFLUSH, &(out.savetty));
	close(out.fd);
}

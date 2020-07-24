/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:46:29 by mgena             #+#    #+#             */
/*   Updated: 2020/07/24 16:56:14 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		set_selection(t_selection *s, const char ch, int fd)
{
	if (ch == 10)
		return (1);
	if (ch == 27)
	{
		ft_fdprintf(fd, "%c[?25h", 27);
		exit(0);
	}
	else if (ch == 32)
		while (!s->under_cursor)
			s = s->next;
		s->selected = !s->selected;
	return (0);

}

char	*get_args_array(t_selection *selection)
{
	t_selection *cpy;
	char *res;
	char *tmp;
	size_t len;
	size_t i;

	res = ft_strdup("");
	len = 1;
	cpy = selection;
	selection = selection->next;
	while (selection != cpy)
	{
		len++;
		selection = selection->next;
	}
	i = 0;
	while (i != len)
	{
		if (selection->selected)
		{
			tmp = ft_strjoin(res, selection->word);
			free(res);
			res = tmp;
			tmp = ft_strjoin(res, " ");
			free(res);
			res = tmp;
			i++;
		}
		else
			len--;
		selection = selection->next;
	}
	return res;
}

char	*choose_args(t_selection *selection, t_outputs out)
{
	char	key[4];
	int		read_bytes;

	while (1)
	{
		ft_putstr_fd(out.CL, out.fd);
		draw_selections(selection, out);
		ft_putstr_fd(out.VI, out.fd);
		read_bytes = read(STDIN_FILENO, key, 4);
		if (read_bytes == 1)
		{
			if (set_selection(selection, key[0], out.fd))
				return (get_args_array(selection));
		}
		else
			move_cursor(&selection, key);
	}
}

char	*select_args(t_selection *selections, t_outputs out)
{
	struct termios	tty;
	struct termios	savetty;
	char			*res;

	if (!(isatty(0)))
	{
		ft_printf("stdin not terminal\n");
		exit(1);
	}
	tcgetattr(0, &tty);
	savetty = tty;
	tty.c_lflag &= ~(ICANON | ECHO | ISIG);
	tty.c_cc[VMIN] = 1;
	tcsetattr(0, TCSAFLUSH, &tty);
	res = choose_args(selections, out);
	ft_putstr_fd(out.VE, out.fd);
	tcsetattr(0, TCSAFLUSH, &savetty);
	return (res);
}

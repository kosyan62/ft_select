/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:46:29 by mgena             #+#    #+#             */
/*   Updated: 2020/08/11 21:53:31 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void 	abort_selections(t_selection **selection, t_outputs out)
{
	ft_putstr_fd(out.VE, out.fd);
	exit(0);
}
void	set_selection(t_selection **selection, t_outputs out)
{
	t_selection *s;

	s = *selection;
	while (!s->under_cursor)
		s = s->next;
	s->selected = !s->selected;
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

void 	empty_function()
{
}

void 	*get_key(char key[4], int read_bytes)
{
//	ft_printf("\n%d: %d %d %d %d\n", read_bytes, key[0], key[1], key[2], key[3]);
//	sleep(1);
	if (!ft_strcmp(key, "\33"))
		return abort_selections;
	else if (!ft_strcmp(key, " "))
		return (set_selection);
	else if (!ft_strcmp(key, "\12"))
		return NULL;
	else if (!ft_strcmp(key, "\177") ||
			(key[0] == 27 && key[1] == 91 && key[2] == 51 && key[3] == 126))
		return (delete_elem);
	else if (!ft_strcmp(key, "\33\133\101"))
		return move_cursor_up;
	else if (!ft_strcmp(key, "\33\133\102"))
		return move_cursor_down;
	else if (!ft_strcmp(key, "\33\133\103"))
		return move_cursor_right;
	else if (!ft_strcmp(key, "\33\133\104"))
		return move_cursor_left;
	return empty_function;
}

char	*choose_args(t_selection *selection, t_outputs out)
{
	char	key[4];
	int		read_bytes;
	void 	(*work_funct)(t_selection**, t_outputs);

	work_funct = NULL;
	while (1)
	{
		selection_storage(selection);
		ft_bzero(key, 4);
		ft_putstr_fd(out.HO, out.fd);
		ft_putstr_fd(out.CD, out.fd);
		draw_selections(selection);
		ft_putstr_fd(out.VI, out.fd);
		read_bytes = read(STDIN_FILENO, key, 4);
		if ((work_funct = get_key(key, read_bytes)) == NULL)
			return (get_args_array(selection));
		work_funct(&selection, out);

	}
	return (NULL);
}

char	*select_args(t_selection *selections, t_outputs out)
{
	struct termios	tty;
	struct termios	savetty;
	char			*res;

	ft_putstr_fd(out.CL, out.fd);
	ft_putstr_fd(out.SC, out.fd);
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
	ft_fdprintf(out.fd, "%s%s%s", out.VE, out.HO, out.CD);
	tcsetattr(0, TCSAFLUSH, &savetty);
	return (res);
}

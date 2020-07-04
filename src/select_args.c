/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:46:29 by mgena             #+#    #+#             */
/*   Updated: 2020/07/04 16:41:46 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		set_selection(t_selection *s, const char ch)
{
	ft_printf("%d", ch);
	if (ch == 10)
		return (1);
	if (ch == 27)
		exit(0);
	else if (ch == 32)
		while (!s->under_cursor)
			s = s->next;
		s->selected = !s->selected;
	return (0);

}

void move_cursor(t_selection **selection, const char key[4])
{
	t_selection *cpy;

	cpy = *selection;
	while (!cpy->under_cursor)
		cpy = cpy->next;
	if (key[0] == 27 && key[1] == 91)
	{
		if (key[2] == 68)
		{
			cpy->under_cursor = false;
			cpy->prev->under_cursor = true;
		}
		else if (key[2] == 67)
		{
			cpy->under_cursor = false;
			cpy->next->under_cursor = true;
		}
		else if (key[2] == 51 && key[3] == 126)
		{
			if (cpy == *selection)
				*selection = cpy->next;
			cpy->next->under_cursor = true;
			del_double_list_item(cpy);
		}
	}
}

char	**get_args_array(t_selection *selection)
{
	return(NULL);
}

char	**choose_args(t_selection *selection)
{
	char	key[4];
	int		read_bytes;
	char	**res;

	while (1)
	{
		ft_printf("%cc", 27);
		draw_selections(selection);
		ft_printf("%c[?25l", 27);
		read_bytes = read(STDIN_FILENO, key, 4);
		if (read_bytes == 1)
		{
			if (set_selection(selection, key[0]))
				return (get_args_array(selection));
		}
		else
			move_cursor(&selection, key);
	}
	return (NULL);
}

char	**select_args(t_selection *selections)
{
	struct termios	tty;
	struct termios	savetty;
	char			**res;

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
	res = choose_args(selections);
	ft_printf("%c[?25h", 27);
	tcsetattr(0, TCSAFLUSH, &savetty);
	return (res);
}

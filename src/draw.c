/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:49:09 by mgena             #+#    #+#             */
/*   Updated: 2020/08/11 22:07:39 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void restore_displayed(t_selection *selection)
{
	t_selection *cpy;

	cpy = selection;
	selection->hor_pos = -1;
	selection->vert_pos = -1;
	selection = selection->next;
	while (selection != cpy)
	{
		selection->hor_pos = -1;
		selection->vert_pos = -1;
		selection = selection->next;
	}
}
void	set_colour_for_type(int fd, mode_t type)
{
	if (S_ISREG(type))
	{
		if (S_IXUSR & type)
			ft_fdprintf(fd, "{red}");
		return;
	}
	else if (S_ISDIR(type))
	{
		if (S_ISVTX & type)
			ft_fdprintf(fd, "\e[102m\e[30m");
		else
			ft_fdprintf(fd, "{blue}");
	}
	else if (S_ISBLK(type))
		ft_fdprintf(fd, "\e[46m\e[94m");
	else if (S_ISCHR(type))
		ft_fdprintf(fd, "\e[43m\e[94m");
	else if (S_ISLNK(type))
		ft_fdprintf(fd, "{magnetic}");
//		ft_fdprintf(fd, "l");
	else if (S_ISSOCK(type))
		ft_fdprintf(fd, "{magnetic}");
}

void 	draw_letters(t_selection *selection, t_outputs out, int cur_line, int wide)
{
	if (selection->under_cursor)
		ft_putstr_fd(out.UL, out.fd);
	if (selection->selected)
		ft_putstr_fd(out.RV, out.fd);
	set_colour_for_type(out.fd, selection->filetype);
	ft_fdprintf(out.fd, "%s{eoc}\e[49m", selection->word);
	ft_putstr_fd(out.NORM, out.fd);
	while ((wide - selection->len - 1) != 0)
	{
//		ft_putchar_fd(' ', out.fd - 1);
		ft_putstr_fd(out.ND, out.fd);
		wide--;
	}
}

void	draw_word(t_selection *selection, int *cur_column, int *cur_line, int cn, t_outputs out)
{
	draw_letters(selection, out, *cur_line, (get_winsize().ws_col / cn));
	selection->vert_pos = *cur_line;
	selection->hor_pos = *cur_column;
	(*cur_column)++;
	if (*cur_column == cn)
	{
//		ft_fdprintf(out.fd, "\n");
		ft_putstr_fd(out.DO, out.fd);
		*cur_column = 0;
		(*cur_line)++;
	}
	else
		ft_fdprintf(out.fd, " ");
}

int		get_max_words_len(t_selection *selection)
{
	t_selection *first;
	int max_len;

	max_len = selection->len;
	first = selection;
	selection = selection->next;
	while (selection != first)
	{
		if (selection->len > max_len)
			max_len = selection->len;
		selection = selection->next;
	}
//	ft_printf(" %d ", max_len);
	return (max_len);
}

int		check_window_size(int len, int fd)
{
	int	screen_size;

	screen_size = get_winsize().ws_col;
	if (len <= 2)
	{
		ft_putstr_fd("..", fd);
		return (0);
	}
	else if (len > screen_size)
	{
		if (screen_size >= 13)
			ft_putstr_fd("Too few space", fd);
		else
			ft_putstr_fd("...", fd);
		return (0);
	}
	else
	{
//		ft_printf("%d %d %d\n", len, (screen_size + 1) / (len + 1), screen_size);
		return (screen_size / (len + 1));
	}
}

void	draw_selections()
{
	int columns_number;
	int cur_column;
	int cur_line;
	t_selection *selection;
	t_selection *first;
	t_outputs out;

	selection = selection_storage(NULL);
	out = out_storage(NULL);
	restore_displayed(selection);
	cur_line = 0;
	cur_column = 0;
	if (!(columns_number = check_window_size(get_max_words_len(selection), out.fd)))
		return ;
//	fill_list_to_screen(selection, get_winsize().ws_row - 1);
	first = selection;
	draw_word(selection, &cur_column, &cur_line, columns_number, out);
	selection = selection->next;
	while (first != selection)
	{
		if (cur_line == get_winsize().ws_row - 1)
		{
			break;
		}
		draw_word(selection, &cur_column, &cur_line, columns_number, out);
		selection = selection->next;
	}
}
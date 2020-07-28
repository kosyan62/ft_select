/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:49:09 by mgena             #+#    #+#             */
/*   Updated: 2020/07/28 17:20:53 by mgena            ###   ########.fr       */
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

void 	draw_letters(t_selection *selection, t_outputs out, int wide)
{
	if (selection->under_cursor)
		ft_putstr_fd(out.UL, out.fd);
	if (selection->selected)
		ft_putstr_fd(out.RV, out.fd);
	ft_fdprintf(out.fd, "%s", selection->word);
	ft_putstr_fd(out.NORM, out.fd);
	while ((wide - selection->len - 1) != 0)
	{
		ft_putchar_fd(' ', out.fd - 1);
		wide--;
	}
}

void	draw_word(t_selection *selection, int *cur_column, int *cur_line, int cn, t_outputs out)
{
	draw_letters(selection, out, (get_winsize().ws_col / cn));
	selection->vert_pos = *cur_line;
	selection->hor_pos = *cur_column;
	(*cur_column)++;
	if (*cur_column == cn)
	{
		ft_fdprintf(out.fd, "\n");
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
		if (screen_size > 13)
			ft_putstr_fd("Too few space", fd);
		else
			ft_putstr_fd("...", fd);
		return (0);
	}
	else
	{
		return (screen_size / (len + 1));
	}
}

void	draw_selections(t_selection *selection, t_outputs out)
{
	int columns_number;
	int cur_column;
	int cur_line;
	t_selection *first;

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
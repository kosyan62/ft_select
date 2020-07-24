/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:49:09 by mgena             #+#    #+#             */
/*   Updated: 2020/07/24 16:34:40 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void restore_displayed(t_selection *selection)
{
	t_selection *cpy;

	cpy = selection;
	cpy->displayed = false;
	selection = selection->next;
	while (selection != cpy)
	{
		selection->displayed = false;
		selection = selection->next;
	}
}

void 	draw_letters(t_selection *selection, t_outputs out)
{
	if (selection->under_cursor)
		ft_putstr_fd(out.UL, out.fd);
	if (selection->selected)
		ft_putstr_fd(out.RV, out.fd);
	ft_fdprintf(out.fd, "%s", selection->word);
	ft_putstr_fd(out.NORM, out.fd);
	selection->displayed = true;
}

void	draw_word(t_selection *selection, int *sl, int *sc, t_outputs out)
{
	if (*sl >= selection->len + 1)
	{
		draw_letters(selection, out);
		ft_fdprintf(out.fd, " ");
		*sl -= selection->len + 1;
	}
	else
	{
		ft_fdprintf(out.fd, "\n");
		(*sc)--;
		*sl = get_winsize().ws_col;
		draw_word(selection, sl, sc, out);
	}
}

void	draw_selections(t_selection *selection, t_outputs out)
{
	int	space_in_line;
	int	space_in_column;
	t_selection *last;

	restore_displayed(selection);
	space_in_line = get_winsize().ws_col;
	space_in_column = get_winsize().ws_row;
	draw_word(selection, &space_in_line, &space_in_column, out);
	last = selection;
	selection = selection->next;
	while (selection != last)
	{
		if ((selection->len > get_winsize().ws_col))
		{
			ft_fdprintf(out.fd, "...");
			break ;
		}
		if (space_in_column == 1 && space_in_line < selection->len)
			break ;
		draw_word(selection, &space_in_line, &space_in_column, out);
		selection = selection->next;
	}
}

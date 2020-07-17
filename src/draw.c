/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:49:09 by mgena             #+#    #+#             */
/*   Updated: 2020/07/17 19:13:48 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void restart_term()
{

}

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

void 	draw_letters(t_selection *selection)
{
	if (selection->under_cursor)
		ft_printf("%c[4m", 27);
	if (selection->selected)
		ft_printf("%c[7m", 27);
	ft_printf("%s", selection->word);
	ft_printf("%c[0m", 27);
	selection->displayed = true;
}

void	draw_word(t_selection *selection, int *sl, int *sc)
{
	struct winsize size;

	if (*sl >= selection->len + 1)
	{
		draw_letters(selection);
		ft_printf(" ");
		*sl -= selection->len + 1;
	}
	else
	{
		ft_printf("\n");
		(*sc)--;
		*sl = get_winsize().ws_col;
		draw_word(selection, sl, sc);
	}
}

void	draw_selections(t_selection *selection)
{
	int	space_in_line;
	int	space_in_column;
	t_selection *last;

	restore_displayed(selection);
	space_in_line = get_winsize().ws_col;
	space_in_column = get_winsize().ws_row;
	draw_word(selection, &space_in_line, &space_in_column);
	last = selection;
	selection = selection->next;
	while (selection != last)
	{
		if ((selection->len > get_winsize().ws_col))
		{
			ft_printf("...");
			break ;
		}
		if (space_in_column == 1 && space_in_line < selection->len)
			break ;
		draw_word(selection, &space_in_line, &space_in_column);
		selection = selection->next;
	}
}

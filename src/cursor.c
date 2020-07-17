/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:46:37 by mgena             #+#    #+#             */
/*   Updated: 2020/07/17 20:07:41 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_selection *move_display_right(t_selection *selection)
{
	struct winsize size;
	int space_in_line;
	int column;

	size = get_winsize();
	space_in_line = size.ws_col;
	column = size.ws_row;
	while (column > 0)
	{
		while (space_in_line >= selection->len + 1)
		{
			space_in_line -= selection->len + 1;
			selection = selection->prev;
		}
		column--;
		space_in_line = size.ws_col;
	}
	return (selection->next);
}

void	move_cursor_right(t_selection **selection, t_selection *cpy)
{
	cpy->under_cursor = false;
	cpy->next->under_cursor = true;
	if (!(cpy->next->displayed))
		*selection = move_display_right(cpy->next);
}

void	move_cursor_left(t_selection **selection, t_selection *cpy)
{
	cpy->under_cursor = false;
	cpy->prev->under_cursor = true;
	if (!(cpy->prev->displayed))
		*selection = cpy->prev;

}

void	move_cursor(t_selection **selection, const char key[4])
{
	t_selection *cpy;

	cpy = *selection;
	while (!cpy->under_cursor)
		cpy = cpy->next;
	if (key[0] == 27 && key[1] == 91)
	{
		if (key[2] == 68)
			move_cursor_left(selection, cpy);
		else if (key[2] == 67)
			move_cursor_right(selection, cpy);
		else if (key[2] == 51 && key[3] == 126)
		{
			if (cpy == *selection)
				*selection = cpy->next;
			cpy->next->under_cursor = true;
			del_double_list_item(cpy);
		}
	}
}


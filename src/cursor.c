/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:46:37 by mgena             #+#    #+#             */
/*   Updated: 2020/07/28 18:06:14 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_selection *move_display_left(t_selection *selection)
{
	t_selection *tmp;

	tmp = selection;
	while (tmp->vert_pos != -1)
	{
		tmp = tmp->next;
		selection = selection->prev;
	}
	return (selection);
}

void	move_cursor_right(t_selection **selection, t_selection *cpy)
{
	cpy->under_cursor = false;
	cpy->next->under_cursor = true;
	if (cpy->next->hor_pos == -1)
		*selection = cpy->next;
}

void	move_cursor_left(t_selection **selection, t_selection *cpy)
{
	cpy->under_cursor = false;
	cpy->prev->under_cursor = true;
	if (cpy->prev->hor_pos == -1)
		*selection = move_display_left(cpy);

}

t_selection	*set_cursor_on_pos(t_selection * cpy, int to_find_hor, int to_find_vert)
{
	t_selection *first;

	first = cpy->next;
	cpy->under_cursor = false;
	while (!(cpy->vert_pos == to_find_vert && cpy->hor_pos == to_find_hor))
	{
//		if (cpy == first)
//		{
//			to_find_vert = 0;
//			to_find_hor++;
//		}
		cpy = cpy->prev;
	}
	cpy->under_cursor = true;
	return (cpy);
}

int			get_max_vert_elem(t_selection *selection)
{
	t_selection *cpy;
	int cur_hor_pos;
	int max_pos;

	cpy = selection;
	max_pos = cpy->vert_pos;
	cur_hor_pos = cpy->hor_pos;
	selection = selection->next;
	while (selection->vert_pos == -1)
		selection = selection->next;
	while (selection != cpy)
	{
		if (selection->hor_pos == cur_hor_pos && selection->vert_pos > max_pos)
			max_pos = selection->vert_pos;
		selection = selection->next;
	}
	return (max_pos);
}

void 	move_cursor_down(t_selection **selection, t_selection *cpy)
{
	int to_find_vert;
	int to_find_hor;
	int max_vert;

	if (cpy->vert_pos == (max_vert = get_max_vert_elem(cpy)))
	{
		if (cpy->next->hor_pos < cpy->hor_pos || !max_vert)
		{
			if (cpy->next->hor_pos == -1 || !max_vert)
				move_cursor_right(selection, cpy);
			else
			{
				cpy = set_cursor_on_pos(cpy, 0, 0);
				ft_printf("\7");
			}
		}
		else
		{
			to_find_hor = cpy->hor_pos;
			to_find_vert = 0;
			cpy = set_cursor_on_pos(cpy, to_find_hor, to_find_vert);
			move_cursor_right(selection, cpy);
		}
	}
	else
	{
		to_find_hor = cpy->hor_pos;
		to_find_vert = cpy->vert_pos + 1;
		set_cursor_on_pos(cpy, to_find_hor, to_find_vert);
	}
}

void 	move_cursor_up(t_selection **selection, t_selection *cpy)
{
	int to_find_vert;
	int to_find_hor;

	if (cpy->vert_pos == 0)
	{
		if (cpy == *selection || 0 == get_max_vert_elem(*selection))
			move_cursor_left(selection, cpy);
		else
		{
			to_find_hor = cpy->hor_pos;
			to_find_vert = get_max_vert_elem(*selection);
			cpy = set_cursor_on_pos(cpy, to_find_hor, to_find_vert);
			move_cursor_left(selection, cpy);
		}
	}
	else
	{
		to_find_hor = cpy->hor_pos;
		to_find_vert = cpy->vert_pos - 1;
		set_cursor_on_pos(cpy, to_find_hor, to_find_vert);
	}
}

void	move_cursor(t_selection **selection, const char key[4], t_outputs out)
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
		else if (key[2] == 65)
			move_cursor_up(selection, cpy);
		else if (key[2] == 66)
			move_cursor_down(selection, cpy);
	}
	if ((key[0] == 27 && key[1] == 91 && key[2] == 51 && key[3] == 126) || key[0] == 127)
	{
		if (cpy == *selection)
			*selection = cpy->next;
		cpy->next->under_cursor = true;
		if (del_double_list_item(cpy))
			escape(out);
	}
}


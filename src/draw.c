/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:49:09 by mgena             #+#    #+#             */
/*   Updated: 2020/07/04 15:02:20 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_word(t_selection selection)
{
	if (selection.under_cursor)
		ft_printf("%c[4m", 27);
	if (selection.selected)
		ft_printf("%c[7m", 27);
	ft_printf("%s", selection.word);
	ft_printf("%c[0m", 27);


}

void	draw_selections(t_selection *selection)
{
	struct winsize	size;
	t_selection		*last;
	size_t			space_in_line;

	size = get_winsize();
	space_in_line = size.ws_col;
	last = selection->prev;
	while (selection != last)
	{
		if (selection->len <= space_in_line)
		{
			draw_word(*selection);
			ft_printf(" ", selection->word);
			space_in_line = space_in_line - selection->len;
		}
		else
		{
			ft_printf("\n");
			draw_word(*selection);
			ft_printf(" ");
			space_in_line = size.ws_row - selection->len;
		}
		selection = selection->next;
	}
}

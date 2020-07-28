/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_side_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:53:03 by mgena             #+#    #+#             */
/*   Updated: 2020/07/28 14:43:21 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_selection	*add_doubly_list(t_selection *lst, char *word, size_t len)
{
	t_selection *new;
	t_selection *p;
	t_selection *temp;

	new = ft_memalloc(sizeof(t_selection));
	new->word = word;
	new->len = len;
	new->under_cursor = false;
	new->selected = false;
	new->vert_pos = -1;
	new->hor_pos = -1;
	if (lst == NULL)
	{
		new->under_cursor = true;
		new->next = new;
		new->prev = new;
		return (new);
	}
	p = lst->prev;
	lst->prev = new;
	new->prev = p;
	new->next = lst;
	p->next = new;
	return (lst);
}

int		del_double_list_item(t_selection *lst)
{
	bool flag;

	flag = false;
	if (lst == lst->next)
		flag = true;
	lst->prev->next = lst->next;
	lst->next->prev = lst->prev;
	ft_strdel(&lst->word);
	free(lst);
	lst = NULL;
	if (flag)
		return (1);
	else
		return (0);
}


void	fill_list_to_screen(t_selection *selection, int elem_on_page)
{
	t_selection	*cpy;
	int 		count;

	count = 1;
	cpy = selection;
	selection = selection->next;
	while (selection != cpy)
	{
		count++;
		selection = selection->next;
	}
	while (elem_on_page < count)
		elem_on_page += elem_on_page;
	while (count++ < elem_on_page)
	{
		ft_printf("%d, %d\n", count, elem_on_page);
		add_doubly_list(selection, "", 0);
	}
}
void del_whole_list(t_selection *lst)
{

}

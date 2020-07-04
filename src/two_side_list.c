/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_side_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:53:03 by mgena             #+#    #+#             */
/*   Updated: 2020/07/04 16:35:01 by mgena            ###   ########.fr       */
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

void del_double_list_item(t_selection *lst)
{
	lst->prev->next = lst->next;
	lst->next->prev = lst->prev;
	ft_strdel(&lst->word);
	free(lst);
}
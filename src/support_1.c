/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:48:13 by mgena             #+#    #+#             */
/*   Updated: 2020/08/12 20:01:14 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_selection	*get_under_cursor(t_selection **selection)
{
	t_selection *cpy;

	cpy = *selection;
	while (!cpy->under_cursor)
		cpy = cpy->next;
	return (cpy);
}

mode_t		get_filetype(char *word)
{
	struct stat buf;

	if (!lstat(word, &buf))
		return (buf.st_mode);
	else
		return (0);
}

t_selection	*selection_storage(t_selection *obj)
{
	static t_selection *storage;

	if (obj == NULL)
		return (storage);
	else
		storage = obj;
	return (NULL);
}

t_outputs	out_storage(t_outputs *obj)
{
	static t_outputs storage;

	if (obj != NULL)
		storage = *obj;
	return (storage);
}

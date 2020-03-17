/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:22:25 by mgena             #+#    #+#             */
/*   Updated: 2019/09/17 21:36:52 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (new == NULL)
		return ;
	new->next = *alst;
	*alst = new;
}

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list *ptr;

	ptr = *alst;
	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

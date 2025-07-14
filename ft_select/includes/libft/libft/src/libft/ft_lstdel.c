/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:36:33 by mgena             #+#    #+#             */
/*   Updated: 2020/01/09 18:51:44 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *nlist;

	nlist = (*alst)->next;
	if (*alst == NULL || del == NULL)
		return ;
	if ((*alst)->next)
		ft_lstdel(&nlist, del);
	ft_lstdelone(alst, del);
}

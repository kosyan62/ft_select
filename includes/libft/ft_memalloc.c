/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 10:22:06 by mgena             #+#    #+#             */
/*   Updated: 2020/02/13 17:20:57 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *res;

	res = malloc(size);
	if (res == NULL)
		return (NULL);
	while (size != 0)
	{
		res[--size] = 0;
	}
	res[0] = 0;
	return (res);
}

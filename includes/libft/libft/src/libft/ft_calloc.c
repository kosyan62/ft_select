/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abortalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:59:25 by mgena             #+#    #+#             */
/*   Updated: 2019/09/18 14:01:37 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	if (!count || !size)
		return (dest = malloc(count * size));
	if (!(dest = (void*)malloc(size * count)))
		return (NULL);
	ft_bzero(dest, count * size);
	return (dest);
}

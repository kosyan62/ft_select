/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:56:44 by mgena             #+#    #+#             */
/*   Updated: 2020/02/25 18:54:03 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	char	*tmp;
	size_t	i;

	i = ft_strlen(s1) + 1;
	tmp = ft_strnew(i);
	if (tmp == NULL)
		malloc_error();
	res = tmp;
	while (i != 0)
	{
		*tmp = *s1;
		tmp++;
		s1++;
		i--;
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:15:12 by mgena             #+#    #+#             */
/*   Updated: 2020/03/06 16:18:09 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc_double(char *str)
{
	char	*res;
	size_t	len;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str) * 2;
	res = ft_strnew(len);
	ft_strcpy(res, str);
	free(str);
	return (res);
}

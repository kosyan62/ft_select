/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:36:36 by mgena             #+#    #+#             */
/*   Updated: 2020/07/21 16:01:41 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

t_selection	*get_arguments(int argc, char **argv)
{
	t_selection	*res;
	size_t		i;
	char		*word;

	i = 1;
	res = NULL;
	while (i < argc)
	{
		word = ft_strdup(argv[i++]);
		res = add_doubly_list(res, word, ft_strlen(word));
	}
	return (res);
}

void		ft_select(int argc, char **argv)
{
	t_selection *arguments;
	char		**selections;

	arguments = get_arguments(argc, argv);
	selections = select_args(arguments);
	while (*selections)
	{
		ft_printf("%s ", *selections);
		selections++;
	}
}

int			main(int argc, char **argv)
{
//	if (argc <= 2)
//		ft_printf("ft_select: to few arguments");
//	else
//		ft_select(argc, argv);
	int  fd;
	fd = open(ttyname(STDOUT_FILENO), O_WRONLY);
	write(fd, "!!!!", 4);
	ft_printf("you suck");

}

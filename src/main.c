/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:36:36 by mgena             #+#    #+#             */
/*   Updated: 2020/07/26 14:36:07 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <termcap.h>


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
	char		*selections;
	t_outputs	out;
	char buf[1024];
	t_selection *first;

//	out.fd = open("debug.txt", O_CREAT|O_RDWR);
	out.fd = open(ttyname(STDIN_FILENO), O_RDWR);
	tinit(&out);
	arguments = get_arguments(argc, argv);
	selections = select_args(arguments, out);
	ft_printf("%s", selections);
	free(selections);
	del_whole_list(arguments);
	close(out.fd);
}

int			main(int argc, char **argv)
{
	if (argc <= 2)
		ft_printf("ft_select: to few arguments");
	else
		ft_select(argc, argv);
}

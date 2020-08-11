/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:36:36 by mgena             #+#    #+#             */
/*   Updated: 2020/08/11 21:53:31 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <termcap.h>

int fd;

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

void		winchhandler(int sig)
{
	t_outputs out;

	if (sig == SIGWINCH)
	{
		out = out_storage(NULL);
//		ft_putstr_fd(out.RC, out.fd);
		ft_putstr_fd(out.HO, out.fd);
		ft_putstr_fd(out.CD, out.fd);
		draw_selections();
//		ft_putstr_fd("!", out.fd);
	}
}

void		ft_select(int argc, char **argv)
{
	t_selection *arguments;
	char		*selections;
	t_outputs	out;

	out.fd = open(ttyname(STDIN_FILENO), O_RDWR);
	tinit(&out);
	out_storage(&out);
	arguments = get_arguments(argc, argv);
	selections = select_args(arguments, out);
	ft_printf("%s", selections);
	free(selections);
	del_whole_list(arguments);
	close(out.fd);


}

int			main(int argc, char **argv)
{
	signal(SIGWINCH, winchhandler);
	if (argc <= 2)
		ft_printf("ft_select: to few arguments");
	else
		ft_select(argc, argv);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:36:36 by mgena             #+#    #+#             */
/*   Updated: 2020/08/14 18:29:15 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_selection	*get_arguments(int argc, char **argv)
{
	t_selection	*res;
	int			i;
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

	main_init();
	arguments = get_arguments(argc, argv);
	selection_storage(arguments);
	selections = select_args(arguments);
	return_tty();
	ft_printf("%s", selections);
	free(selections);
}

int			main(int argc, char **argv)
{
	init_signals();
	if (argc <= 2)
		ft_printf("ft_select: to few arguments");
	else
		ft_select(argc, argv);
}

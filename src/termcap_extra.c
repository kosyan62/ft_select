/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 14:48:09 by mgena             #+#    #+#             */
/*   Updated: 2020/08/07 15:00:32 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int put(int c)
{
	write(1, &c, 1);
	return (1);
}
void	tinit(t_outputs *out)
{
	int error;
	out->p = out->strings;
	error = tgetent(out->tbuf, out->tname = getenv("TERM"));
	if (error == -1)
	{
		ft_printf("Нет файла TERMCAP\n");
		exit(1);
	}
	else if (error == 0)
	{
		ft_printf("Терминал %s не описан\n", out->tname);
		exit(2);
	}
	else if (error == 1)
	{
		out->CL = tgetstr("cl", &out->p);
		out->CD = tgetstr("cd", &out->p);
		out->RV = tgetstr("mr", &out->p);
		out->UL = tgetstr("us", &out->p);
		out->NORM = tgetstr("me", &out->p);
		out->VI = tgetstr("vi", &out->p);
		out->VE = tgetstr("ve", &out->p);
		out->HO = tgetstr("ho", &out->p);
		out->SC = tgetstr("sc", &out->p);
		out->RC = tgetstr("rc", &out->p);
		out->ND = tgetstr("nd", &out->p);
		out->DO = tgetstr("do", &out->p);
	}

	else
	{
		ft_printf("Unnamed error");
		exit(1);
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 14:48:09 by mgena             #+#    #+#             */
/*   Updated: 2020/08/12 20:06:33 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_term_str(t_outputs *out)
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

void	tinit(t_outputs *out)
{
	int error;

	out->p = out->strings;
	out->tname = getenv("TERM");
	error = tgetent(out->tbuf, out->tname);
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
		set_term_str(out);
	else
	{
		ft_printf("Unnamed error");
		exit(1);
	}
}

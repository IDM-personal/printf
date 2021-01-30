/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelgado <idelgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 23:33:00 by idm               #+#    #+#             */
/*   Updated: 2021/01/30 20:06:18 by idelgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_resolve_string_imp(char *cad, t_flag *flg, int *flenght, int ilength)
{
	if (flg->leftjust)
	{
		ft_putstr_n(cad, flg->precision, flenght);
		if (flg->precision != -1 && flg->precision < ilength)
			ft_putblanks(flg->width - flg->precision, flenght);
		else if (flg->width > ilength)
			ft_putblanks(flg->width - ilength, flenght);
	}
	else if (flg->zero)
	{
		if (flg->precision != -1 && flg->precision < ilength)
			ft_putzeros(flg->width - flg->precision, flenght);
		else if (flg->width > ilength)
			ft_putzeros(flg->width - ilength, flenght);
		ft_putstr_n(cad, flg->precision, flenght);
	}
	else
	{
		if (flg->precision != -1 && flg->precision < ilength)
			ft_putblanks(flg->width - flg->precision, flenght);
		else if (flg->width > ilength)
			ft_putblanks(flg->width - ilength, flenght);
		ft_putstr_n(cad, flg->precision, flenght);
	}
}

void	ft_resolve_string(char *cad, t_flag *flg, int *flenght)
{
	int ilength;

	ilength = ft_strlen(cad);
	if (flg->width != -1 || flg->precision != -1)
	{
		if (flg->precision > flg->width)
		{
			if (flg->precision > ilength)
			{
				if (!(flg->precision < ilength) && !(ilength > flg->width))
					ft_putblanks(flg->width, flenght);
				ft_putstr(cad, flenght);
			}
			else
				ft_putstr_n(cad, flg->precision, flenght);
		}
		else
			ft_resolve_string_imp(cad, flg, flenght, ilength);
	}
	else
	{
		ft_putstr(cad, flenght);
	}
}

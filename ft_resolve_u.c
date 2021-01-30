/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelgado <idelgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:42:47 by root              #+#    #+#             */
/*   Updated: 2021/01/30 19:57:08 by idelgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_resolve_u_wmp_lj(char *cad, t_flag *flg, int *flenght, int ilength)
{
	if (flg->precision > ilength)
		ft_putzeros(flg->precision - ilength, flenght);
	if (flg->width != 0 && flg->precision != 0 || ft_atoi(cad) != 0)
		ft_putstr(cad, flenght);
	if (flg->precision != -1)
	{
		if (flg->precision > ilength || flg->precision == 0)
			ft_putblanks(flg->width - flg->precision, flenght);
		else if (flg->width > ilength)
			ft_putblanks(flg->width - ilength, flenght);
	}
	else if (ilength < flg->width)
		ft_putblanks(flg->width - ilength, flenght);
}

void	ft_resolve_u_wmp_notlj_imp(char *cad, t_flag *flg, int *flenght, int i)
{
	if (ft_atoi(cad) != 0)
	{
		if (flg->width > i)
			ft_putblanks(flg->width - i, flenght);
		ft_putstr(cad, flenght);
	}
	else
		ft_putblanks(flg->width, flenght);
	flg->precision = 0;
}

void	ft_resolve_u_wmp_notlj(char *cad, t_flag *flg, int *flenght, int il)
{
	if (flg->precision != -1)
	{
		if (il > flg->precision)
			ft_resolve_u_wmp_notlj_imp(cad, flg, flenght, il);
		else if (flg->precision == 0)
		{
			ft_putblanks(flg->width - flg->precision, flenght);
			if (ft_itoa(cad) != 0)
				ft_putstr(cad, flenght);
		}
		else if (flg->precision > il)
		{
			ft_putblanks(flg->width - flg->precision, flenght);
			ft_putzeros(flg->precision - il, flenght);
		}
		else if (flg->width > il)
			ft_putblanks(flg->width - il, flenght);
	}
	else if (flg->zero == 1 && il < flg->width)
		ft_putzeros(flg->width - il, flenght);
	else if (il < flg->width)
		ft_putblanks(flg->width - il, flenght);
	if (flg->width != 0 && flg->precision != 0)
		ft_putstr(cad, flenght);
}

void	ft_resolve_u(char *cad, t_flag *flg, int *flenght)
{
	int ilength;

	ilength = ft_strlen(cad);
	if (flg->width != -1 || flg->precision != -1)
	{
		if (flg->precision > flg->width)
		{
			if (flg->precision >= ilength)
			{
				ft_putzeros(flg->precision - ilength, flenght);
				ft_putstr(cad, flenght);
			}
			else
				ft_putstr(cad, flenght);
		}
		else if (flg->leftjust)
			ft_resolve_u_wmp_lj(cad, flg, flenght, ilength);
		else
			ft_resolve_u_wmp_notlj(cad, flg, flenght, ilength);
	}
	else
		ft_putstr(cad, flenght);
}

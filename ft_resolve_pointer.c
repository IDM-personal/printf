/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelgado <idelgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 01:49:32 by idm               #+#    #+#             */
/*   Updated: 2021/01/30 20:36:33 by idelgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rptr_wmpandil_lj(char *cad, t_flag *flg, int ilength, int *flenght)
{
	if (flg->precision > ilength)
	{
		ft_putstr("0x", flenght);
		ft_putzeros(flg->precision - ilength + 2, flenght);
		ft_putstr(cad, flenght);
	}
	else if (flg->width != 0 && flg->precision != 0)
		ft_putstr(ft_strjoin("0x", cad), flenght);
	if (flg->precision != -1)
	{
		if (flg->precision > ilength || flg->precision == 0)
			ft_putblanks(flg->width - flg->precision - 2, flenght);
		else if (flg->width > ilength)
			ft_putblanks(flg->width - ilength, flenght);
	}
	else if (ilength < flg->width)
		ft_putblanks(flg->width - ilength, flenght);
}

void	ft_rptr_contrary_pn0(char *cad, t_flag *flg, int ilength, int *flenght)
{
	if (flg->precision == 0)
	{
		ft_putblanks(flg->width - flg->precision - 2, flenght);
		ft_putstr("0x", flenght);
	}
	else if (flg->precision > ilength)
	{
		ft_putblanks(flg->width - flg->precision - 2, flenght);
		ft_putstr("0x", flenght);
		ft_putzeros(flg->precision - ilength + 2, flenght);
		ft_putstr(cad, flenght);
		return ;
	}
	else if (flg->width > ilength)
		ft_putblanks(flg->width - ilength, flenght);
}

void	ft_rptr_contrary(char *cad, t_flag *flg, int ilength, int *flenght)
{
	if (flg->precision != -1)
		ft_rptr_contrary_pn0(cad, flg, ilength, flenght);
	else if (flg->zero == 1 && ilength < flg->width)
	{
		ft_putstr("0x", flenght);
		ft_putzeros(flg->width - ilength, flenght);
		ft_putstr(cad, flenght);
		return ;
	}
	else if (flg->width > ilength && !flg->zero)
	{
		ft_putblanks(flg->width - ilength, flenght);
		ft_putstr(ft_strjoin("0x", cad), flenght);
		return ;
	}
	else if (ilength < flg->width)
		ft_putblanks(flg->width - ilength, flenght);
	if (flg->width != 0 && flg->precision != 0)
		ft_putstr(ft_strjoin("0x", cad), flenght);
}

void	ft_resolve_ptr_parts(char *cad, t_flag *flg, int ilength, int *flenght)
{
	if (flg->width > ilength)
	{
		if (flg->leftjust)
			ft_rptr_wmpandil_lj(cad, flg, ilength, flenght);
		else
			ft_rptr_contrary(cad, flg, ilength, flenght);
	}
	else
	{
		ft_putstr("0x", flenght);
		ft_putstr_n(cad, flg->precision, flenght);
	}
}

void	ft_resolve_pointer(char *cad, t_flag *flg, int *flenght)
{
	int ilength;

	ilength = ft_strlen(cad) + 2;
	if (flg->width != -1 || flg->precision != -1)
	{
		if (flg->precision > flg->width)
		{
			if (flg->precision + 1 >= ilength)
			{
				ft_putstr("0x", flenght);
				ft_putzeros(flg->precision - ilength + 2, flenght);
				ft_putstr(cad, flenght);
			}
			else
				ft_putstr(ft_strjoin("0x", cad), flenght);
		}
		else
			ft_resolve_ptr_parts(cad, flg, ilength, flenght);
	}
	else
		ft_putstr(ft_strjoin("0x", cad), flenght);
}

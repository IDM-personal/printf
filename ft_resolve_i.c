/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelgado <idelgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:03:55 by root              #+#    #+#             */
/*   Updated: 2021/01/30 20:30:07 by idelgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nrego(int i, t_flag *flg, int *flenght)
{
	char			*cad;
	unsigned int	i2;

	cad = ft_itoa(i);
	if (i < 0)
	{
		i2 = i;
		if (i * -1 < 0)
			cad = ft_itoau(i2);
		else
			cad = ft_itoa(i * -1);
		ft_resolve_i_neg(cad, flg, flenght);
		return (1);
	}
	return (0);
}

void	ft_resolve_i_wmp_lj(char *cad, t_flag *flg, int *flenght)
{
	int	ilength;

	ilength = ft_strlen(cad);
	if (flg->precision > ilength)
		ft_putzeros(flg->precision - ilength, flenght);
	if (flg->width != 0 && flg->precision != 0 || ft_atoi(cad) != 0)
		ft_putstr(cad, flenght);
	if (flg->precision != -1)
	{
		if (ft_atoi(cad) == 0)
			ft_putblanks(flg->width - flg->precision, flenght);
		else if (flg->precision > ilength)
			ft_putblanks(flg->width - flg->precision, flenght);
		else if (flg->width > ilength)
			ft_putblanks(flg->width - ilength, flenght);
	}
	else if (ilength < flg->width)
		ft_putblanks(flg->width - ilength, flenght);
}

void	ft_resolve_i_wmp_notlj_imp(char *cad, t_flag *flg, int *flenght, int i)
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

void	ft_resolve_i_wmp_notlj(char *cad, t_flag *flg, int *flenght)
{
	int	ilength;

	ilength = ft_strlen(cad);
	if (flg->precision != -1)
	{
		if (ilength > flg->precision)
			ft_resolve_i_wmp_notlj_imp(cad, flg, flenght, ilength);
		else if (flg->precision == 0)
			ft_putblanks(flg->width - flg->precision, flenght);
		else if (flg->precision > ilength)
		{
			ft_putblanks(flg->width - flg->precision, flenght);
			ft_putzeros(flg->precision - ilength, flenght);
		}
		else if (flg->width > ilength)
			ft_putblanks(flg->width - ilength, flenght);
	}
	else if (flg->zero == 1 && ilength < flg->width)
		ft_putzeros(flg->width - ilength, flenght);
	else if (ilength < flg->width)
		ft_putblanks(flg->width - ilength, flenght);
	if (flg->width != 0 && flg->precision != 0)
		ft_putstr(cad, flenght);
}

void	ft_resolve_i(int i, t_flag *flg, int *flenght)
{
	int		ilength;
	char	*cad;

	cad = ft_itoa(i);
	ilength = ft_strlen(cad);
	if (ft_nrego(i, flg, flenght))
		return ;
	if (flg->width != -1 || flg->precision != -1)
	{
		if (flg->precision > flg->width)
		{
			if (flg->precision >= ilength)
				ft_putzeros(flg->precision - ilength, flenght);
			ft_putstr(cad, flenght);
		}
		else if (flg->leftjust)
			ft_resolve_i_wmp_lj(cad, flg, flenght);
		else
			ft_resolve_i_wmp_notlj(cad, flg, flenght);
	}
	else
		ft_putstr(cad, flenght);
}

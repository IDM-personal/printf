/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_i_neg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelgado <idelgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:12:34 by idelgado          #+#    #+#             */
/*   Updated: 2021/01/30 20:27:01 by idelgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_resolve_i_neg_wm_lj(char *cad, t_flag *flg, int *flenght, int il)
{
	if (flg->precision > il)
	{
		ft_putchar('-', flenght);
		ft_putzeros(flg->precision - il + 1, flenght);
		ft_putstr(cad, flenght);
	}
	else if (flg->width != 0 && flg->precision != 0)
		ft_putstr(ft_strjoin("-", cad), flenght);
	if (flg->precision != -1)
	{
		if (flg->precision > il || flg->precision == 0)
			ft_putblanks(flg->width - flg->precision - 1, flenght);
		else if (flg->width > il)
			ft_putblanks(flg->width - il, flenght);
	}
	else if (il < flg->width)
		ft_putblanks(flg->width - il, flenght);
}

void	ft_resolve_i_neg_wm_notlj_pset(char *cad, t_flag *flg, int *f, int il)
{
	if (flg->precision == 0)
		ft_putblanks(flg->width - flg->precision, f);
	else if (flg->precision > il)
	{
		ft_putblanks(flg->width - flg->precision - 1, f);
		ft_putchar('-', f);
		ft_putzeros(flg->precision - il + 1, f);
		ft_putstr(cad, f);
		flg->precision = 0;
	}
	else if (flg->width > il)
		ft_putblanks(flg->width - il, f);
}

void	ft_resolve_i_neg_wm_notlj(char *cad, t_flag *flg, int *flenght, int il)
{
	if (flg->precision != -1)
		ft_resolve_i_neg_wm_notlj_pset(cad, flg, flenght, il);
	else if (flg->zero == 1 && il < flg->width)
	{
		ft_putchar('-', flenght);
		ft_putzeros(flg->width - il, flenght);
		ft_putstr(cad, flenght);
		return ;
	}
	else if (flg->width > il && !flg->zero)
	{
		ft_putblanks(flg->width - il, flenght);
		ft_putstr(ft_strjoin("-", cad), flenght);
		return ;
	}
	else if (il < flg->width)
		ft_putblanks(flg->width - il, flenght);
	if (flg->width != 0 && flg->precision != 0)
		ft_putstr(ft_strjoin("-", cad), flenght);
}

void	ft_resolve_i_neg(char *cad, t_flag *flg, int *flenght)
{
	int ilength;

	ilength = ft_strlen(cad) + 1;
	if (flg->width != -1 || flg->precision != -1)
	{
		if (flg->precision > flg->width)
		{
			if (flg->precision >= ilength)
			{
				ft_putchar('-', flenght);
				ft_putzeros(flg->precision - ilength + 1, flenght);
				ft_putstr(cad, flenght);
			}
			else
				ft_putstr(ft_strjoin("-", cad), flenght);
		}
		else if (flg->leftjust)
			ft_resolve_i_neg_wm_lj(cad, flg, flenght, ilength);
		else
			ft_resolve_i_neg_wm_notlj(cad, flg, flenght, ilength);
	}
	else
		ft_putstr(ft_strjoin("-", cad), flenght);
}

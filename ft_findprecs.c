/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findprecs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelgado <idelgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 17:50:42 by idelgado          #+#    #+#             */
/*   Updated: 2021/01/30 18:09:23 by idelgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fw(char *cad, t_flag *flg)
{
	char	*width;
	int		i;

	i = 0;
	width = malloc(sizeof(char*));
	while (*cad)
	{
		if (*cad == '-')
		{
			flg->leftjust = 1;
			fw(ft_substr(cad, 1, ft_strlen(cad)), flg);
			return ;
		}
		width[i++] = *cad++;
	}
	flg->width = ft_atoi(width);
}

char	*fww(char *wp, t_flag *flg, va_list args)
{
	while (*wp != '.')
	{
		if (*wp == '*')
		{
			flg->width = va_arg(args, int);
			fw(ft_replace(wp, '*', ft_itoa(flg->width)), flg);
			wp = ft_substr(wp, ft_strpchr(wp, '.'), ft_strlen(wp));
		}
		else if (*wp)
		{
			fw(wp, flg);
			wp = ft_substr(wp, ft_strpchr(wp, '.'), ft_strlen(wp));
		}
	}
	return (wp);
}

void	fwp(char *wp, t_flag *flg, va_list args)
{
	while (*wp != 0)
	{
		*wp++;
		if (*wp == '-')
			findprec(wp, flg);
		if (*wp == '*')
		{
			flg->precision = va_arg(args, int);
			findprec(ft_replace(wp, '*', ft_itoa(flg->precision)), flg);
			return ;
		}
		findprec(wp, flg);
		return ;
	}
}

void	findprec(char *cad, t_flag *flg)
{
	char	*prec;
	int		i;

	i = 0;
	prec = malloc(sizeof(char*));
	while (*cad)
	{
		if (*cad == '-')
		{
			flg->precision = -1;
			if (flg->width == 0)
				flg->width = -1;
			return ;
		}
		prec[i++] = *cad++;
	}
	flg->precision = ft_atoi(prec);
}

void	findwp(char *wp, t_flag *flg, va_list args)
{
	if (*wp)
	{
		if (ft_strpchr(wp, '0') == 0)
		{
			flg->zero = 1;
			wp++;
		}
		if (*wp == '-')
		{
			flg->leftjust = 1;
			return (findwp(ft_substr(wp, 1, ft_strlen(wp)), flg, args));
		}
		wp = fww(wp, flg, args);
		fwp(wp, flg, args);
	}
}

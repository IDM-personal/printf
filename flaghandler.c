/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flaghandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelgado <idelgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:20:46 by idelgado          #+#    #+#             */
/*   Updated: 2021/01/30 18:09:40 by idelgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*initstruct(void)
{
	t_flag	*flag;

	flag = (t_flag*)(malloc(sizeof(t_flag)));
	flag->type = 0;
	flag->zero = 0;
	flag->leftjust = 0;
	flag->width = -1;
	flag->precision = -1;
	return (flag);
}

char	*ft_replace(char *cad, char toreplace, char *replacer)
{
	char	*newcad;

	newcad = malloc(ft_strlen(cad) + ft_strlen(replacer));
	if (cad)
		while (*cad)
		{
			if (*cad == toreplace)
			{
				newcad = ft_substr(cad, 0, ft_strpchr(cad, '*'));
				newcad = ft_strjoin(newcad, replacer);
				return (newcad);
			}
			*cad++;
		}
}

void	flm(char *mods, t_flag *flg, va_list args)
{
	if (ft_strrchr(mods, '.'))
		findwp(mods, flg, args);
	else
		while (*mods)
		{
			if (*mods == '-')
			{
				flg->leftjust = 1;
				return (flm(ft_substr(mods, 1, ft_strlen(mods)), flg, args));
			}
			if (*mods == '*')
			{
				flg->width = va_arg(args, int);
				return (fw(ft_replace(mods, '*', ft_itoa(flg->width)), flg));
			}
			if (ft_strpchr(mods, '0') == 0)
				flg->zero = 1;
			else
				return (fw(mods, flg));
			mods++;
		}
}

char	*flaghandler(char *srcfrompercent, va_list args, int *len)
{
	t_flag	*flg;
	char	*src;
	int		stat;

	flg = initstruct();
	stat = 0;
	src = ft_strdup(srcfrompercent);
	while (*srcfrompercent++ != 0)
		if (ft_strrchr("cspdiuxX%", *srcfrompercent) != 0)
		{
			flg->type = *srcfrompercent++;
			break ;
		}
		else
			stat++;
	if (stat > 0)
		flm(ft_substr(src, 1, stat), flg, args);
	flagmuncher(args, flg, len);
	while (*srcfrompercent != '\0')
	{
		if (*srcfrompercent == '%')
			return (srcfrompercent);
		ft_putchar(*srcfrompercent++, len);
	}
	return (NULL);
}

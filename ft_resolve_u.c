/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:42:47 by root              #+#    #+#             */
/*   Updated: 2021/01/19 20:44:37 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_resolve_u(char *cad, t_flag *flg, int *flenght)
{
    int ilength;

    ilength = ft_strlen(cad);
    if(flg->width != -1 || flg->precision != -1)
    {
        if(flg->precision > flg->width)
        {
            if(flg->precision >= ilength)
            {
                ft_putzeros(flg->precision - ilength, flenght);
                ft_putstr(cad, flenght);
            }
            else
                ft_putstr(cad, flenght);
        }else
        {
            if(flg->leftjust)
            {
                if(flg->precision > ilength)
                    ft_putzeros(flg->precision - ilength, flenght);
                if(flg->width != 0 && flg->precision != 0)
                    ft_putstr(cad, flenght);
                if(flg->precision != -1)
                {
                    if(flg->precision > ilength || flg->precision == 0)
                        ft_putblanks(flg->width - flg->precision, flenght);
                    else if(flg->width > ilength)
                        ft_putblanks(flg->width - ilength, flenght);
                }
                else if(ilength < flg->width)
                    ft_putblanks(flg->width - ilength, flenght);
            }
            else
            {
                //printf("%i <> %i <> %i <> %i \n", flg->zero, flg->width, flg->precision, ilength);
                if(flg->zero && flg->width > ilength && flg->precision > ilength)
                    ft_putzeros(flg->width - ilength, flenght);
                else if(flg->precision != -1)
                {
                    if(flg->precision == 0)
                        ft_putblanks(flg->width - flg->precision, flenght);
                    else if(flg->precision > ilength)
                    {
                        ft_putblanks(flg->width - flg->precision, flenght);
                        ft_putzeros(flg->precision - ilength, flenght);
                    }
                    else if(flg->width > ilength)
                        ft_putblanks(flg->width - ilength, flenght);
                }
                else if(flg->zero == 1 && ilength < flg->width)
                    ft_putzeros(flg->width - ilength, flenght);
                else if(ilength < flg->width)
                    ft_putblanks(flg->width - ilength, flenght);
                if(flg->width != 0 && flg->precision != 0)
                    ft_putstr(cad, flenght);
            }
        }
    }
    else
        ft_putstr(cad, flenght);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idm <idm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 23:33:00 by idm               #+#    #+#             */
/*   Updated: 2021/01/12 21:16:47 by idm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_resolve_string(char *cad, t_flag *flg, int *flenght)
{
    int ilength;
    int rtvalue;

    rtvalue = 0;
    ilength = ft_strlen(cad);
    if(flg->width != -1 || flg->precision != -1)
    {
        if(flg->precision > flg->width)
        {
            if(flg->precision > ilength)
            {
                if(flg->precision < ilength)
                    rtvalue = flg->precision;
                else
                    rtvalue = ilength;
                ft_putstr_fd(cad,1);
            }
            else
            {
                rtvalue = flg->precision;
                ft_putstr_n(cad,flg->precision);
            }
        }
        else
        {
            if(flg->zero)
            {
                if(flg->precision != -1 && flg->precision < ilength)
                    ft_putzeros(flg->width - flg->precision);
                else if(flg->width > ilength)
                    ft_putzeros(flg->width - ilength);
                ft_putstr_n(cad,flg->precision);
                rtvalue = (flg->width);
            }
            else if(flg->leftjust)
            {
                ft_putstr_n(cad,flg->precision);
                if(flg->precision != -1 && flg->precision < ilength)
                    ft_putblanks(flg->width - flg->precision);
                else if(flg->width > ilength)
                    ft_putblanks(flg->width - ilength);
                rtvalue = (flg->width);
            }
            else
            {
                if(flg->precision != -1 && flg->precision < ilength)
                    ft_putblanks(flg->width - flg->precision);
                else if(flg->width > ilength)
                    ft_putblanks(flg->width - ilength);
                ft_putstr_n(cad,flg->precision);
                rtvalue = flg->width;
            }
            if((ilength > flg->width && flg->precision <= 0 && flg->width != flg->precision) && cad == NULL)
                rtvalue = ilength;
        }
    }
    else
    {
        rtvalue = ilength;
        ft_putstr_fd(cad, 1);
    }
    *flenght += rtvalue;
}
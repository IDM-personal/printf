/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idm <idm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 01:49:32 by idm               #+#    #+#             */
/*   Updated: 2021/01/12 23:11:00 by idm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_resolve_hex(char *cad, t_flag *flg, int *flenght)
{
    int ilength;

    ilength = ft_strlen(cad);
    if(flg->width != -1 || flg->precision != -1)
    {
        if(flg->precision > flg->width)
        {
            if(flg->precision > ilength)
            {
                if(flg->precision > ilength)
                    *flenght += flg->precision;
                else
                    *flenght += ilength;
                ft_putzeros(flg->precision - ilength);
                ft_putstr_fd(cad,1);
            }
        }else
        {
            if(ilength > flg->width)
                *flenght += ilength;
            else
                *flenght += flg->width;
            if(flg->leftjust)
            {
                if(flg->precision > ilength)
                    ft_putzeros(flg->precision - ilength);
                ft_putstr_fd(cad, 1);
                if(flg->precision != -1)
                    ft_putblanks(flg->width - flg->precision);
                else
                    ft_putblanks(flg->width - ilength);
            }
            else
            {
                if(flg->precision != -1)
                    ft_putblanks(flg->width - ilength);
                else if(ilength < flg->width)
                    ft_putblanks(flg->width - ilength);
                ft_putstr_fd(cad, 1);
            }
        }
    }
    else
    {
        *flenght += ilength;
        ft_putstr_fd(cad, 1);
    }
}
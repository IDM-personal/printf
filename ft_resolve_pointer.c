/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idm <idm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 01:49:32 by idm               #+#    #+#             */
/*   Updated: 2021/01/13 07:31:46 by idm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_resolve_pointer(char *cad, t_flag *flg, int *flenght)
{
    int ilength;
    
    ilength = ft_strlen(cad) + 2;
    if(flg->precision != -1 || flg->width != 1)
    {
        if(flg->precision > flg->width)
        {
            ft_putstr("0x", flenght);
            if(flg->precision > ilength)
            {
                *flenght += flg->precision + flg->width;
                ft_putzeros(flg->precision - ilength + flg->width, flenght);
            }
            else
                *flenght += ilength;
            ft_putstr_n(cad, flg->precision, flenght);
        }
        else
        {
            if(flg->width > ilength)
            {
                if(flg->leftjust)
                {
                    ft_putstr("0x", flenght);
                    if(flg->precision > ilength)
                        ft_putzeros(flg->precision - ilength, flenght);
                    else
                        ft_putstr(cad, flenght);
                    ft_putblanks(flg->width - flg->precision - ilength, flenght);
                }
                else if (flg->zero)
                {
                    ft_putstr("0x", flenght);
                    ft_putblanks(flg->width - flg->precision - ilength, flenght);
                }
                else
                {
                    if(flg->precision == 0 || flg->precision < ilength)
                        ft_putblanks(flg->width - ilength + 1, flenght);
                    else
                        ft_putblanks(flg->width - flg->precision - ilength, flenght);
                    ft_putstr("0x", flenght);
                    if(flg->precision > ilength)
                        ft_putzeros(flg->precision - ilength, flenght);
                    else
                        ft_putstr_n(cad, flg->precision, flenght);
                }
                *flenght += flg->width;
            }
            else
            {
                ft_putstr("0x", flenght);
                ft_putstr_n(cad, flg->precision, flenght);
                *flenght += ilength;
            }
        }
    }
    else
    {
        ft_putstr("0x", flenght);
        if(flg->width != 0 && flg->precision !=0)
            ft_putstr(cad, flenght);
        *flenght += ilength;
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 01:49:32 by idm               #+#    #+#             */
/*   Updated: 2021/01/20 22:21:33 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_resolve_pointer(char *cad, t_flag *flg, int *flenght)
{
    int ilength;

    ilength = ft_strlen(cad) + 2;
    if(flg->width != -1 || flg->precision != -1)
    {
        if(flg->precision > flg->width)
        {
            if(flg->precision >= ilength)
            {
                ft_putstr("0x", flenght);
                ft_putzeros(flg->precision - ilength, flenght);
                ft_putstr(cad, flenght);
            }
            else
                ft_putstr(ft_strjoin("0x",cad), flenght);
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
                    if(flg->precision == -1)
                        ft_putblanks(flg->width - ilength, flenght);
                    else if(flg->precision < ilength)
                        ft_putblanks(flg->width - ilength + 1, flenght);
                    else
                        ft_putblanks(flg->width - flg->precision - ilength, flenght);
                    ft_putstr("0x", flenght);
                    if(flg->precision > ilength)
                        ft_putzeros(flg->precision - ilength, flenght);
                    else
                        ft_putstr_n(cad, flg->precision, flenght);
                }
            }
            else
            {
                ft_putstr("0x", flenght);
                ft_putstr_n(cad, flg->precision, flenght);
            }
        }
    }
    else
        ft_putstr(ft_strjoin("0x",cad), flenght);
}



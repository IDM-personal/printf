/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idm <idm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 01:49:32 by idm               #+#    #+#             */
/*   Updated: 2021/01/13 06:48:58 by idm              ###   ########.fr       */
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
            ft_putstr_fd("0x",1);
            if(flg->precision > ilength)
            {
                *flenght += flg->precision;
                ft_putzeros(flg->precision - ilength);
            }
            else
                *flenght += ilength;
            ft_putstr_fd(cad,1);
        }
        else
        {
            if(flg->width > ilength)
            {
                if(flg->leftjust)
                {
                    ft_putstr_fd("0x",1);
                    if(flg->precision > ilength)
                        ft_putzeros(flg->precision - ilength);
                    else
                        ft_putstr_fd(cad, 1);
                    ft_putblanks(flg->width - flg->precision - ilength);
                }
                else if (flg->zero)
                {
                    ft_putstr_fd("0x",1);
                    ft_putblanks(flg->width - flg->precision - ilength);
                }
                else
                {
                    if(flg->precision == -1)
                        ft_putblanks(flg->width - ilength);
                    else
                        ft_putblanks(flg->width - flg->precision - ilength);
                    ft_putstr_fd("0x",1);
                    if(flg->precision > ilength)
                        ft_putzeros(flg->precision - ilength);
                    else
                        ft_putstr_fd(cad, 1);
                }
                *flenght += flg->width;
            }
            else
            {
                ft_putstr_fd("0x",1);
                ft_putstr_fd(cad,1);
                *flenght += ilength;
            }
        }
    }
    else
    {
        ft_putstr_fd("0x",1);
        ft_putstr_fd(cad, 1);
        *flenght += ilength;
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idm <idm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 01:49:32 by idm               #+#    #+#             */
/*   Updated: 2021/01/13 01:18:27 by idm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_resolve_char(int n, t_flag *flg, int *flenght)
{
    int ilength;

    ilength = 1;
    if(flg->width != -1 || flg->precision != -1)
    {
        if(flg->precision > flg->width)
        {
            if(flg->precision >= ilength)
            {
                if(flg->precision > ilength)
                    *flenght += flg->precision;
                else
                    *flenght += ilength;
                ft_putzeros(flg->precision - ilength);
                ft_putchar_fd(n, 1);
            }
            else
            {
                *flenght += ilength;
                ft_putchar_fd(n, 1);
            }
        }else
        {
            if(ilength > flg->width && flg->width != 0)
                *flenght += ilength;
            else
                *flenght += flg->width;
            if(flg->leftjust)
            {
                if(flg->precision > ilength)
                    ft_putzeros(flg->precision - ilength);
                if(flg->width != 0 && flg->precision != 0)
                    ft_putchar_fd(n, 1);
                if(flg->precision != -1)
                {
                    if(flg->precision > ilength || flg->precision == 0)
                        ft_putblanks(flg->width - flg->precision);
                    else if(flg->width > ilength)
                        ft_putblanks(flg->width - ilength);
                }
                else if(ilength < flg->width)
                    ft_putblanks(flg->width - ilength);
            }
            else
            {
                if(flg->zero && flg->width > ilength)
                    ft_putzeros(flg->width - ilength);
                else if(flg->precision != -1)
                {
                    if(flg->precision == 0)
                        ft_putblanks(flg->width - flg->precision);
                    else if(flg->precision > ilength)
                    {
                        ft_putblanks(flg->width - flg->precision);
                        ft_putzeros(flg->precision - ilength);
                    }
                    else if(flg->width > ilength)
                        ft_putblanks(flg->width - ilength);
                }
                else if(ilength < flg->width)
                    ft_putblanks(flg->width - ilength);
                if(flg->width != 0 && flg->precision != 0)
                    ft_putchar_fd(n, 1);
            }
        }
    }
    else
    {
        *flenght += ilength;
        ft_putchar_fd(n, 1);
    }
}
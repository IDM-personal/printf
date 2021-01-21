/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 01:49:32 by idm               #+#    #+#             */
/*   Updated: 2021/01/21 22:44:27 by root             ###   ########.fr       */
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
            if(flg->precision >= ilength && flg->width > 0)
            {
                ft_putzeros(flg->precision - ilength, flenght);
                if(flg->width > ilength)
                    ft_putchar(n, flenght);
            }
            else
                ft_putchar(n, flenght);
        }else
        {
            if(flg->leftjust)
            {
                /* if(flg->precision > ilength)
                    ft_putzeros(flg->precision - ilength, flenght); */
                if(flg->width != 0 && flg->precision != 0)
                    ft_putchar(n, flenght);
                if(flg->precision != -1)
                    ft_putblanks(flg->width - ilength, flenght);
                else if(ilength < flg->width)
                    ft_putblanks(flg->width - ilength, flenght);
            }
            else
            {
                if(flg->zero && flg->width > ilength)
                    ft_putzeros(flg->width - ilength, flenght);
                else if(flg->precision != -1)
                {
                    if(flg->precision == 0)
                        ft_putblanks(flg->width - flg->precision, flenght);
                    else 
                        ft_putblanks(flg->width - ilength, flenght);
                }
                else if(ilength < flg->width)
                    ft_putblanks(flg->width - ilength, flenght);
                if(flg->width != 0 || flg->precision != 0)
                    ft_putchar(n, flenght);
            }
        }
    }
    else
        ft_putchar(n, flenght);
}
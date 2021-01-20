/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:03:55 by root              #+#    #+#             */
/*   Updated: 2021/01/20 21:23:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_resolve_i_neg(char *cad, t_flag *flg, int *flenght)
{
    int ilength;

    ilength = ft_strlen(cad) + 1;
    if(flg->width != -1 || flg->precision != -1)
    {
        if(flg->precision > flg->width)
        {
            if(flg->precision >= ilength)
            {
                ft_putchar('-', flenght);
                ft_putzeros(flg->precision - ilength + 1, flenght);
                ft_putstr(cad, flenght);
            }
            else
                ft_putstr(ft_strjoin("-",cad), flenght);
        }
        else
        {
            if(flg->leftjust)
            {
                if(flg->precision > ilength)
                {
                    ft_putchar('-', flenght);
                    ft_putzeros(flg->precision - ilength + 1, flenght);
                    ft_putstr(cad, flenght);
                }
                else if(flg->width != 0 && flg->precision != 0)
                    ft_putstr(ft_strjoin("-",cad), flenght);
                if(flg->precision != -1)
                {
                    if(flg->precision > ilength || flg->precision == 0)
                        ft_putblanks(flg->width - flg->precision - 1, flenght);
                    else if(flg->width > ilength)
                        ft_putblanks(flg->width - ilength, flenght);
                }
                else if(ilength < flg->width)
                    ft_putblanks(flg->width - ilength, flenght);
            }
            else
            {
                if(flg->precision != -1)
                {
                    if(flg->precision == 0)
                        ft_putblanks(flg->width - flg->precision, flenght);
                    else if(flg->precision > ilength)
                    {
                        ft_putblanks(flg->width - flg->precision - 1, flenght);
                        ft_putchar('-',flenght);
                        ft_putzeros(flg->precision - ilength + 1, flenght);
                        ft_putstr(cad, flenght);
                        return ;
                    }
                    else if(flg->width > ilength)
                        ft_putblanks(flg->width - ilength, flenght);
                }
                else if(flg->zero == 1 && ilength < flg->width)
                {
                    ft_putchar('-', flenght);
                    ft_putzeros(flg->width - ilength, flenght);
                    ft_putstr(cad, flenght);
                    return ;
                }
                else if(flg->width > ilength && !flg->zero)
                {
                    ft_putblanks(flg->width - ilength, flenght);
                    ft_putstr(ft_strjoin("-",cad), flenght);
                    return ;
                }
                else if(ilength < flg->width)
                    ft_putblanks(flg->width - ilength, flenght);
                if(flg->width != 0 && flg->precision != 0)
                    ft_putstr(ft_strjoin("-",cad), flenght);
            }
        }
    }
    else
        ft_putstr(ft_strjoin("-",cad), flenght);
}

void ft_resolve_i(int i, t_flag *flg, int *flenght)
{
    int ilength;
    int neg;
    char *cad;

    cad = ft_itoa(i);
    neg = 0;
    ilength = ft_strlen(cad);
    if(i < 0)
    {
        cad = ft_itoa(i * -1);
        if(i * -1 < 0)
            ft_putstr(ft_itoa(i), flenght);
        else
            ft_resolve_i_neg(cad, flg, flenght);
        return ;
    }
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
        }
        else
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
                if(flg->precision != -1)
                {
                    if(flg->precision == 0)
                        ft_putblanks(flg->width - flg->precision, flenght);
                    else if(flg->precision > ilength)
                    {
                        ft_putblanks(flg->width - flg->precision , flenght);
                        ft_putzeros(flg->precision - ilength , flenght);
                    }
                    else if(flg->width > ilength)
                        ft_putblanks(flg->width - ilength, flenght);
                }
                else if(flg->zero == 1 && ilength < flg->width)
                {
                    ft_putzeros(flg->width - ilength, flenght);
                }
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



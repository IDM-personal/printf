/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idm <idm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 23:33:00 by idm               #+#    #+#             */
/*   Updated: 2021/01/12 04:39:44 by idm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_resolve_string(char *cad, t_flag *flg, int *flenght)
{
    int ilength;
    
    ilength = ft_strlen(cad);
    if(flg->width != -1 || flg->precision != -1)
    {
        if(flg->precision > flg->width)
        {
            if(flg->precision > ilength)
            {
                if(flg->precision < ilength)
                    *flenght += flg->precision;
                else
                    *flenght += ilength;
                ft_putstr_fd(cad,1);
            }
            else
            {
                *flenght += flg->precision;
                ft_putstr_n(cad,flg->precision);
            }
        }
        else
        {
            if(ilength > flg->width)
                *flenght = ilength;
            if(flg->leftjust)
            {
                ft_putstr_n(cad,flg->precision);
                if(flg->precision != -1)
                    ft_putblanks(flg->width - flg->precision);
                else
                    ft_putblanks(flg->width - ilength);
                *flenght += (1 + flg->width);
            }
            else
            {
                if(flg->precision != -1)
                    ft_putblanks(flg->width - flg->precision);
                else if(flg->width > ilength)
                    ft_putblanks(flg->width - ilength);
                ft_putstr_n(cad,flg->precision);
                *flenght += flg->width + 1;
            }
        }
    }
    else
    {
        *flenght += ilength;
        ft_putstr_fd(cad, 1);
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idm <idm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 01:49:32 by idm               #+#    #+#             */
/*   Updated: 2021/01/13 00:16:27 by idm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_resolve_pointer(char *cad, t_flag *flg, int *flenght)
{
    int ilength;

    ilength = ft_strlen(cad);
    *flenght += 2;
    ft_putstr_fd("0x",1);
    if(flg->precision != -1)
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
            ft_putstr_fd(cad,1);
            *flenght += ilength;
        }
    }
    else
    {
        *flenght += ilength;
        ft_putstr_fd(cad, 1);
    }
}
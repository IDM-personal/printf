/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_pct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idm <idm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 05:20:26 by idm               #+#    #+#             */
/*   Updated: 2021/01/13 05:37:02 by idm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_resolve_pct(char pct, t_flag *flg, int *flenght)
{
    if(flg->width != -1)
    {
        if(flg->leftjust)
        {
            ft_putchar_fd(pct, 1);
            ft_putblanks(flg->width - 1);
        }
        else if(flg->zero)
        {
            ft_putzeros(flg->width - 1);
            ft_putchar_fd(pct, 1);
        }
        else
        {
            ft_putblanks(flg->width - 1);
            ft_putchar_fd(pct, 1);
        }
        *flenght += flg->width;
        return ;
    }
    else
        ft_putchar_fd(pct, 1);
    *flenght += 1;
}
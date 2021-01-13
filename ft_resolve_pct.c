/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_pct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idm <idm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 05:20:26 by idm               #+#    #+#             */
/*   Updated: 2021/01/13 07:30:30 by idm              ###   ########.fr       */
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
            ft_putblanks(flg->width - 1, flenght);
        }
        else if(flg->zero)
        {
            ft_putzeros(flg->width - 1, flenght);
            ft_putchar_fd(pct, 1);
        }
        else
        {
            ft_putblanks(flg->width - 1, flenght);
            ft_putchar_fd(pct, 1);
        }
        return ;
    }
    else
        ft_putchar_fd(pct, 1);
}
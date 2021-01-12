/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_formal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idm <idm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:53:18 by idm               #+#    #+#             */
/*   Updated: 2021/01/12 22:08:35 by idm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char* flagValues = "cspdiuxX%";

void    flagmuncher(char type, va_list args, t_flag *flg, int *flenght)
{
    char *cad;
    int n;
    
    if(type == '%')
    {
        ft_putchar_fd('%',1);
        flenght += 1;
        return ;
    }
    if(type == 's')
    {
        cad = va_arg(args, char*);
        if(cad == NULL)
        {
            flg->isnull = 1;
            cad = "(null)";
        }
        ft_resolve_string(cad, flg, flenght);
        return ;
    }
    if(type == 'p')
    {
        cad = va_arg(args, char*);
        cad = ft_itohex_t((void *)cad,0);
        ft_resolve_pointer(cad, flg, flenght);
        return ;
    }
    n = va_arg(args, int);
    if(type == 'c')
    {
        ft_putchar_fd(n,1);
        flenght += 1;
    }
    if(type == 'x')
    {
        cad = ft_itohex_t(n,0);
        ft_resolve_hex(cad, flg, flenght);
        flenght += ft_strlen(cad);
    }
    if(type == 'X')
    {
        cad = ft_itohex_t(n,1);
        ft_resolve_hex(cad, flg, flenght);
        flenght += ft_strlen(cad);
    }
}

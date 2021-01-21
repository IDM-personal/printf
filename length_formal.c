/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_formal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:53:18 by idm               #+#    #+#             */
/*   Updated: 2021/01/21 15:15:21 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char* flagValues = "cspdiuxX%";

void    flagmuncher(char type, va_list args, t_flag *flg, int *flenght)
{
    char *cad;
    int n;
    
    if(type == '%')
        ft_resolve_pct('%', flg, flenght);
    else if(type == 's')
    {
        cad = va_arg(args, char*);
        if(cad == 0)
            cad = "(null)";
        ft_resolve_string(cad, flg, flenght);
    }
    else if(type == 'u')
    {
        n = va_arg(args, unsigned int);
        ft_resolve_u(ft_itoau(n), flg, flenght);
    }
    else if(type == 'p')
    {
        unsigned long val = va_arg(args, unsigned long);
        cad = ft_itohex_u(val,0);
        ft_resolve_pointer(cad, flg, flenght);
    }
    else
        n = va_arg(args, int);
    if(n == 0 && flg->precision <= 0)
        return;
    if(type == 'c')
        ft_resolve_char(n, flg, flenght);
    if(type == 'x')
    {
        cad = ft_itohex_t(n,0);
        ft_resolve_hex(cad, flg, flenght);
    }
    if(type == 'X')
    {
        cad = ft_itohex_t(n,1);
        ft_resolve_hex(cad, flg, flenght);
    }
    if(type == 'i')
        ft_resolve_i(n, flg, flenght);
    if(type == 'd')
        ft_resolve_i(n, flg, flenght);
}

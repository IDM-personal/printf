/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_formal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idm <idm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:53:18 by idm               #+#    #+#             */
/*   Updated: 2021/01/13 06:16:46 by idm              ###   ########.fr       */
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
    else if(type == 'p')
    {
        cad = va_arg(args, char*);
        ft_resolve_pointer(cad, flg, flenght);
    }
    else
        n = va_arg(args, int);
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
}

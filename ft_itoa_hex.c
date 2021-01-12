/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idm <idm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:45:14 by idelgado          #+#    #+#             */
/*   Updated: 2021/01/12 03:36:57 by idm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_rev(char *src)
{
	int i;
    int len = ft_strlen(src);
    char c;

	i = 0;
	while (i != (len / 2))
	{
        c = src[i];
        src[i] = src[len - i - 1]; 
        src[len - i - 1] = c;
		i++;
	}
    return &src[0];
}

char *ft_itohex_t(int itohex, int caps)
{
    char *hextable;
    char *hexval = (char*)(malloc(sizeof(char*)));
    unsigned int ival;
    int i = 0;

    ival = itohex;
    if(caps == 1)
        hextable = "0123456789ABCDEF";
    else
        hextable = "0123456789abcdef";
    while(ival > 15)
    {
        hexval[i++] = hextable[ival % 16];
        ival /= 16;
    }
    hexval[i] = hextable[ival];
    return ft_rev(&hexval[0]);
}

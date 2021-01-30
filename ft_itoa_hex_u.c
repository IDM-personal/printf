/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelgado <idelgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:45:14 by idelgado          #+#    #+#             */
/*   Updated: 2021/01/30 18:36:49 by idelgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itohex_u(unsigned long itohex, int caps)
{
	char			*hextable;
	char			*hexval;
	unsigned long	ival;
	int				i;

	i = 0;
	hexval = (char*)(malloc(sizeof(char*)));
	ival = itohex;
	if (caps == 1)
		hextable = "0123456789ABCDEF";
	else
		hextable = "0123456789abcdef";
	while (ival > 15)
	{
		hexval[i++] = hextable[ival % 16];
		ival /= 16;
	}
	hexval[i] = hextable[ival];
	return (ft_rev(&hexval[0]));
}

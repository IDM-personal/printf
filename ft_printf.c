/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelgado <idelgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:45:09 by idelgado          #+#    #+#             */
/*   Updated: 2020/11/30 16:45:25 by idelgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_printf(const char *src, ...)
{
	va_list args;
	
	va_start(args, src);
	while(*src != '\0')
	{
		while(*src == '%')
		{
			//start flaghandler
			if((src = flaghandler(ft_strdup(src),args)) == NULL)
				return (0);
		}
		ft_putchar_fd(*src,1);
		src++;
	}
	va_end(args);
	return (0);
}

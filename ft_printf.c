/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idm <idm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:45:09 by idelgado          #+#    #+#             */
/*   Updated: 2021/01/13 10:09:28 by idm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_printf(const char *src, ...)
{
	va_list args;
	int		length;
	
	length = 0;
	va_start(args, src);
	while(*src != '\0')
	{
		while(*src == '%')
		{
			//start flaghandler
			if((src = flaghandler(ft_strdup(src),args,&length)) == NULL)
				return (length);
		}
		ft_putchar(*src, &length);
		src++;
	}
	va_end(args);
	if(length == 0)
		return (0);
	else
		return (length);
}

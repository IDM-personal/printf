/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelgado <idelgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:45:09 by idelgado          #+#    #+#             */
/*   Updated: 2020/10/07 20:12:19 by idelgado         ###   ########.fr       */
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

int main()
{
	printf("%112.223s-\n","hahahaha");
	printf("%5.15X-\n",1222);
	printf("%15.5s-\n","hellode");
	printf("%10.5d-",2);
	printf("%10*.5d-",2);
	ft_printf("%-112.223s-\n",1222);
	ft_printf("%5.115x-\n",1222);
	ft_printf("%10.5d-",2);
	ft_printf("%10*.*d",225,210,10);
	ft_printf("%10.5d-",2);
	/*ft_printf("%250.250d",25);
	ft_printf("esto deberia salir entero%caa\naa%s%%%s\nzorra",'1',"pitos de mono",3,"holabuenas",'c');
	ft_printf("\nSos un boludo violador\n%s\n","y la cada");
	ft_printf("\nSos un boludo violador\n%*.*d\n",2,4);*/
}

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
	va_end(args);
	while(*src != '\0')
	{
		while(*src == '%')
		{
			//start flaghandler
			if((src = flaghandler(ft_strdup(src))) == NULL)
				return (0);
			//printf("\nSRC NEXT TO FLAG CALL : %s\n",src);
		}
		ft_putchar_fd(*src,1);
		src++;
	}
	// if(ft_strchr(src, '%'))
	// {
	// 	printf("flag start\n");
	// 	int fgstart = ft_strpchr(src,'%');
	// 	printf("%i", fgstart);
	// 	char *cad = (char*)(src + fgstart + 1);
	// 	int nextfg = ft_strpchr(cad, '%');
	// 	if(nextfg == 0)
	// 	{
	// 		nextfg = ft_strpchr(src,'\0');
	// 	}
	// 	printf("%i", nextfg);
	// 	printf("flagcontent -> %s\n", ft_substr(src,fgstart + 1,nextfg));
	// 	printf("%s",cad);
	// }
	return (0);
}

int main()
{
	//int number = 10;
	ft_printf("esto deberia salir entero%caa\naa%s%%%s",1,2,3,"holabuenas",'c');
	printf("%*.*d",10,5,35);
	// printf("\n%caa-10d\n", number);
	// //printf("%13.1i \n", 232,2);
    // printf("%-#10x \n", number);
    // printf("%-20d \n", 20000);
}

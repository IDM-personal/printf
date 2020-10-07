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
	if(ft_strchr(src, '%'))
	{
		printf("flag start\n");
		int fgstart = ft_strpchr(src,'%');
		printf("%i", fgstart);
		char *cad = (char*)(src + fgstart + 1);
		int nextfg = ft_strpchr(cad, '%');
		if(nextfg == 0)
		{
			nextfg = ft_strpchr(src,'\0');
		}
		printf("%i", nextfg);
		printf("flagcontent -> %s\n", ft_substr(src,fgstart + 1,nextfg));
		printf("%s",cad);
	}
	printf("%i",va_arg(args,int));
	printf("%i",va_arg(args,int));
	printf("%-i\n",va_arg(args,int));
	char *x = va_arg(args,char *);
	
	ft_putstr_fd(x,0);
	
	printf("\n%-c",va_arg(args,int));
	return (0);
}

int main()
{
	int number = 10;
	ft_printf("%caaaa%s%%%s",1,2,3,"holabuenas",'c');
	printf("\n%caa-10d\n", number);
	printf("%+-+13.1i \n", 232,2);
    printf("%-#10x \n", number);
    printf("%-20d \n", 20000);
}

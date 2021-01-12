/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flaghandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idm <idm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:20:46 by idelgado          #+#    #+#             */
/*   Updated: 2021/01/12 01:28:26 by idm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char* flagValues = "cspdiuxX%";

void    findwp(char *cadwp, t_flag *flg, va_list args)
{
    int wstat = 0,pstat = 0, width = 0, prec = 0, i = 0;
    char *ogcadwp = ft_strdup(cadwp);
    if(*cadwp)
    {
        if(ft_strrchr(cadwp,'-'))
        {
            wstat++;
            flg->leftjust = 1;
            cadwp++;
        }
        while(*cadwp != '.')
        {
            if(*cadwp == '*')
            {
                if(i != 0)
                    return ;
                flg->width = va_arg(args, int);
            }
            if(*cadwp <= '9' && *cadwp >= '0')
                i++;
            cadwp++;
        }
        if(flg->width == -1)
            flg->width = ft_atoi(ft_substr(ogcadwp,wstat,i));
        wstat += i + 1;
        i = 0;
        while(*cadwp++ != 0)
        {
            if(*cadwp == '*')
            {
                if(i != 0)
                    return ;
                flg->precision = va_arg(args, int);
            }
            if(*cadwp <= '9' && *cadwp >= '0')
                i++;
            cadwp++;
        }
        if(flg->precision == -1)
            flg->precision = ft_atoi(ft_substr(ogcadwp,wstat,i + 1));
    }
}

void    flagmods(char *modscad, t_flag *flg, va_list args)
{
    if(ft_strrchr(modscad,'.'))
    {
        findwp(modscad, flg, args);
    }else
        while(*modscad)
            if(ft_strrchr("0",*modscad++))
                flg->zero = 1;
}

void cum(t_flag *flg)
{
    printf("\nTIPO : %c\n", flg->type);
    printf("\nZERO : %d\n", flg->zero);
    printf("\nLEFT JUST: %d\n", flg->leftjust);
    printf("\nWIDTH : %d\n", flg->width);
    printf("\nPRECISION : %d\n", flg->precision);
}

void initstruct(t_flag *flag){
	flag->type = 0;
	flag->zero = 0;
	flag->leftjust = 0;
	flag->width = -1;
	flag->precision = -1;
}

char    *flaghandler(char *srcfrompercent, va_list args, int *len)
{
	t_flag *flg = (t_flag*)(malloc(sizeof(t_flag)));
    initstruct(flg);
    int stat = 0;
    char *src = ft_strdup(srcfrompercent);
    while(*srcfrompercent++ != 0)
    {
        if(ft_strrchr(flagValues,*srcfrompercent) != 0)
        {
            flg->type = *srcfrompercent++;
            break;
        }else
            stat++;
    }
    if(stat > 0)
        flagmods(ft_substr(src,1,stat),flg,args);
    flagmuncher(flg->type,args,flg,len);
    while(*srcfrompercent != '\0')
    {
        if(*srcfrompercent == '%')
            return(srcfrompercent);
        *len += 1;
		ft_putchar_fd(*srcfrompercent,1);
        srcfrompercent++;
    }
    return (NULL);
}

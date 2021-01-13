/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flaghandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idm <idm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:20:46 by idelgado          #+#    #+#             */
/*   Updated: 2021/01/13 10:50:28 by idm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char* flagValues = "cspdiuxX%";

void    findwp(char *cadwp, t_flag *flg, va_list args)
{
    int i = 0;
    char *width = malloc(sizeof(char*));
    char *precision = malloc(sizeof(char*));
    flg->width = 0;
    flg->precision = 0;
    if(*cadwp)
    {
        if(ft_strrchr(cadwp,'-'))
        {
            flg->leftjust = 1;
            cadwp++;
        }
        while(*cadwp != 0)
        {
            if(*cadwp == '.')
                break ;
            if(*cadwp == '*')
            {
                if(i != 0)
                    return ;
                flg->width = va_arg(args, int);
            }
            if(*cadwp <= '9' && *cadwp >= '0')
                width[i++] = *cadwp;
            cadwp++;
        }
        if(flg->width <= 0)
            flg->width = ft_atoi(width);
        i = 0;
        while(*cadwp != 0)
        {
            if(*cadwp == '*')
            {
                if(i != 0)
                    return ;
                flg->precision = va_arg(args, int);
            }
            if(*cadwp <= '9' && *cadwp >= '0')
                precision[i++] = *cadwp;
            cadwp++;
        }
        if(flg->precision <= 0)
            flg->precision = ft_atoi(precision);
    }
}

void    flagmods(char *modscad, t_flag *flg, va_list args)
{
    char *width;
    int i;

    i = 0;
    width = malloc(sizeof(char*));
    if(ft_strrchr(modscad,'.'))
        findwp(modscad, flg, args);
    else
        while(*modscad)
        {
            if(ft_strrchr("-",*modscad))
            {
                flg->leftjust = 1;
                *modscad++;
            }
            if(ft_strrchr("0",*modscad))
                flg->zero = 1;
            if(*modscad == '*')
            {
                flagmods(ft_itoa(va_arg(args, int)),flg , args);
                return ;
            }
            else
                width[i++] = *modscad;
            *modscad++;
        }
    flg->width = ft_atoi(width);
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
    char* flagValues;
    flagValues = "cspdiuxX%";
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
    //printf("VALOR DE STAT : %i",stat);
    if(stat > 0)
        flagmods(ft_substr(src,1,stat),flg,args);
    //cum(flg);
    flagmuncher(flg->type,args,flg,len);
    while(*srcfrompercent != '\0')
    {
        if(*srcfrompercent == '%')
            return(srcfrompercent);
		ft_putchar(*srcfrompercent, len);
        srcfrompercent++;
    }
    return (NULL);
}

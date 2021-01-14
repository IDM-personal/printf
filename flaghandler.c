/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flaghandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idm <idm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:20:46 by idelgado          #+#    #+#             */
/*   Updated: 2021/01/14 01:57:22 by idm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char* flagValues = "cspdiuxX%";

void    findprec(char *cad, t_flag *flg)
{
    char *prec;
    int i;

    //printf("CADENA PREC : %s",cad);
    i = 0;
    prec = malloc(sizeof(char*));
    while(*cad)
    {
        //printf("%c\n", *cad);
        if(*cad == '-')
        {
            findprec(ft_substr(cad, 1,ft_strlen(cad)),flg);
            return ;
        }
        prec[i++] = *cad++;
    }
    flg->precision = ft_atoi(prec);
}

void    findwidth(char *cad, t_flag *flg)
{
    char *width;
    int i;

    //printf("CADENA : %s",cad);
    i = 0;
    width = malloc(sizeof(char*));
    while(*cad)
    {
        //printf("%c\n", *cad);
        if(*cad == '-')
            {
                flg->leftjust = 1;
                findwidth(ft_substr(cad, 1,ft_strlen(cad)),flg);
                return ;
            }
        width[i++] = *cad++;
    }
    flg->width = ft_atoi(width);
}

void    findwp(char *cadwp, t_flag *flg, va_list args)
{
    int i = 0;
    char *width = malloc(sizeof(char*));
    char *precision = malloc(sizeof(char*));
    flg->width = 0;
    flg->precision = 0;
    if(*cadwp)
    {
        while(*cadwp != '.')
        {
            if(*cadwp == '-')
            {
                flg->leftjust = 1;
                findwp(ft_substr(cadwp, 1,ft_strlen(cadwp)),flg, args);
            }
            if(*cadwp == '*')
            {
                if(i != 0)
                    return ;
                flg->width = va_arg(args, int);
            }
            if(ft_strpchr("modscad", '0') == 0)
                flg->zero = 1;
            else 
            {
                findwidth(cadwp, flg);
                cadwp = ft_substr(cadwp,  ft_strpchr(cadwp, '.'), ft_strlen(cadwp));
                //printf("hola %s\n", cadwp);
            }
        }
        if(flg->width <= 0)
            flg->width = ft_atoi(width);
        i = 0;
        while(*cadwp != 0)
        {
            *cadwp++;
            if(*cadwp == '-')
                findwp(ft_substr(cadwp, 1,ft_strlen(cadwp)),flg, args);
            if(*cadwp == '*')
            {
                if(i != 0)
                    return ;
                flg->precision = va_arg(args, int);
                if(flg->precision < 1)
                    flg->precision = -1;
                return ;
            }
            findprec(cadwp, flg);
            return ;
        }
        if(flg->precision <= 0)
            flg->precision = ft_atoi(precision);
    }
}

void    flagmods(char *modscad, t_flag *flg, va_list args)
{
    if(ft_strrchr(modscad,'.'))
    {
        findwp(modscad, flg, args);
        return ;
    }
    else
        while(*modscad)
        {
            //printf("CAD MODS : %s",modscad);
            if(*modscad == '-')
            {
                flg->leftjust = 1;
                flagmods(ft_substr(modscad, 1,ft_strlen(modscad)),flg,args);
                return ;
            }
            if(*modscad == '*')
            {
                flg->width = va_arg(args, int);
                return ;
            }
            if(ft_strpchr(modscad, '0') == 0)
                flg->zero = 1;
            else 
            {
                findwidth(modscad, flg);
                return ;
            }
            *modscad++;
        }
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

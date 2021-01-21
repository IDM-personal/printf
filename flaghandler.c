/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flaghandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:20:46 by idelgado          #+#    #+#             */
/*   Updated: 2021/01/21 14:53:27 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char* flagValues = "cspdiuxX%";

char    *ft_replace(char *cad, char toreplace, char *replacer)
{
    char    *newcad;

    newcad = malloc(ft_strlen(cad) + ft_strlen(replacer));
    if(cad)
        while(*cad)
        {
            if(*cad == toreplace)
            {
                newcad = ft_substr(cad, 0, ft_strpchr(cad, '*'));
                newcad = ft_strjoin(newcad, replacer);
                return(newcad);
            }
            *cad++;
        }
    
}

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
            flg->precision = -1;
            if(flg->width == 0)
                flg->width = -1;
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
    flg->width = -1;
    flg->precision = -1;
    if(*cadwp)
    {
        while(*cadwp != '.')
        {
            if(*cadwp == '-')
            {
                flg->leftjust = 1;
                findwp(ft_substr(cadwp, 1,ft_strlen(cadwp)),flg, args);
                return ;
            }
            if(ft_strpchr(cadwp, '0') == 0)
                flg->zero = 1;
            if(*cadwp == '*')
            {
                flg->width = va_arg(args, int);
                findwidth(ft_replace(cadwp, '*', ft_itoa(flg->width)), flg);
                cadwp = ft_substr(cadwp, ft_strpchr(cadwp, '.'), ft_strlen(cadwp));
            }
            else if(*cadwp)
            {
                findwidth(cadwp, flg);
                cadwp = ft_substr(cadwp,  ft_strpchr(cadwp, '.'), ft_strlen(cadwp));
            }
        }
        if(flg->width <= 0  && flg->precision != -1)
            flg->width = ft_atoi(width);
        i = 0;
        while(*cadwp != 0)
        {
            *cadwp++;
            if(*cadwp == '-')
                findprec(cadwp,flg);
            if(*cadwp == '*')
            {
                flg->precision = va_arg(args, int);
                findprec(ft_replace(cadwp, '*', ft_itoa(flg->precision)), flg);
                return ;
            }
            findprec(cadwp, flg);
            return ;
        }
        if(flg->precision <= 0 && flg->precision != -1)
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
                findwidth(ft_replace(modscad, '*', ft_itoa(flg->width)), flg);
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

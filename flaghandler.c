/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flaghandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelgado <idelgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:20:46 by idelgado          #+#    #+#             */
/*   Updated: 2020/11/23 19:02:21 by idelgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char* flagValues = "cspdiuxX%";

void    flagmuncher(char type, va_list args)
{
    char *cad;
    int n;
    if(type == '%')
        ft_putchar_fd('%',1);
    if(type == 's')
    {
        cad = va_arg(args, char*); 
        ft_putstr_fd(cad,1);
    }
    n = va_arg(args, int);
    if(type == 'c')
        ft_putchar_fd(n,1);
}

void    findwp(char *cadwp, t_flag *flg, va_list args)
{
    int wstat = 0,pstat = 0, width = 0, prec = 0, i = 0;
    char *ogcadwp = ft_strdup(cadwp);
    printf("\nCADENA FIND WIDTH PREC %s\n",cadwp);
    va_arg(args,char*);
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
        if(flg->width == 0)
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
        if(flg->precision == 0)
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
    printf("\nCONTENIDO : %s\n", flg->content);
}

void initstruct(t_flag *flag){
	flag->type = '0';
	flag->zero = 0;
	flag->leftjust = 0;
	flag->width = 0;
	flag->precision = 0;
	flag->content = "\0";
}

char    *flaghandler(char *srcfrompercent, va_list args)
{
	t_flag *flg = (t_flag*)(malloc(sizeof(t_flag)));
    int stat = 0;
    char *src = ft_strdup(srcfrompercent);
    printf("\nPUNTEROS IWALES : %p\n", flg);
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
    flg->content = srcfrompercent;
    flg->content =  ft_substr(flg->content,0 ,ft_strpchr(flg->content,'%'));
    cum(flg);
    flagmuncher(flg->type,args);
    while(*srcfrompercent != '\0')
    {
        if(*srcfrompercent == '%')
            return(srcfrompercent);
		ft_putchar_fd(*srcfrompercent,1);
        srcfrompercent++;
    }
    return (NULL);
}

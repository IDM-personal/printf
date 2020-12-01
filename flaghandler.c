/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flaghandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelgado <idelgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:20:46 by idelgado          #+#    #+#             */
/*   Updated: 2020/12/01 11:36:56 by idelgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    flagmuncher(char type, va_list args)
{
    char *cad;
    int n;
    if(type == '%')
        ft_putchar_fd('%',1);
    /*if(type == 's')
    {
        cad = va_arg(args, char*); 
        ft_putstr_fd(cad,1);
    }*/
    n = va_arg(args, int);
    if(type == 'c')
        ft_putchar_fd(n,1);
    if(type == 'x')
        ft_print_hex(n, 0);
    if(type == 'X')
        ft_print_hex(n,1);
    if(type == 'p')
    {
        write(1, "0x", 2);
        ft_print_hex(n,0);
    }
        
}

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
		flg->width = ft_atoi(ft_substr(ogcadwp, wstat, i));
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
    printf("SEG FAULT");
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
	flag->type = 0;
	flag->zero = 0;
	flag->leftjust = 0;
	flag->width = -1;
	flag->precision = -1;
	flag->content = (char*)(malloc(sizeof(char*)));
}

char    *flaghandler(char *srcfrompercent, va_list args)
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
    if(stat > 0)
        flagmods(ft_substr(src,1,stat),flg,args);
    flg->content = srcfrompercent;
    flg->content =  ft_substr(flg->content,0 ,ft_strpchr(flg->content,'%'));
    cum(flg);
    printf("\nSEG FAULT precum \n");
    flagmuncher(flg->type,args);
    cum(flg);
    while(*srcfrompercent != '\0')
    {
        if(*srcfrompercent == '%')
            return(srcfrompercent);
		ft_putchar_fd(*srcfrompercent,1);
        srcfrompercent++;
    }
    return (NULL);
}

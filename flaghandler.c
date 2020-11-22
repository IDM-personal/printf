/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flaghandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelgado <idelgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:20:46 by idelgado          #+#    #+#             */
/*   Updated: 2020/10/07 18:21:14 by idelgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char* flagValues = "cspdiuxX%";

char	*flaghandler(char *srcfrompercent)
{
    //printf("POSIBLES FLAG VALUES : %s", flagValues);
    //printf("\nCALL A FLAGHANDLER\n");
    //printf("\nCADENA EN FLAGHANDLER : %s\n",srcfrompercent);
	t_flag flg;
    while(*srcfrompercent++ != 0)
    {
        if(ft_strrchr(flagValues,*srcfrompercent) != 0)
        {
            flg.type = *srcfrompercent++;
            break;
        }
    }
    flg.content = srcfrompercent;
    flg.content =  ft_substr(flg.content,0 ,ft_strpchr(flg.content,'%'));
    ft_putstr_fd(flg.content,1);
    //printf("\nSRC THAT SHOULD GO BACK FLAGCALL : %s\n",srcfrompercent);
    printf("\nFLAG : %c\n",flg.type);
    //call flagmuncher
    while(*srcfrompercent != '\0')
    {
        if(*srcfrompercent == '%')
            return(srcfrompercent);
        *srcfrompercent++;
    }
    printf("\nHE FUCKED UP\n");
    
    //printf("\nNIGGA \n");
    //printf("\nFLAG CONTENT : %s\n",flg.content);
    return (NULL);
}

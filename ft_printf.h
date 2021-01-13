/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idm <idm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:48:58 by idelgado          #+#    #+#             */
/*   Updated: 2021/01/13 05:22:57 by idm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_flag
{
    char type;
    int zero;
    int leftjust;
    int width;
    int precision;
    char *content;
}t_flag;

char    *flaghandler(char *srcfrompercent, va_list args, int *len);
int     ft_printf(const char *, ...);
char    *ft_itohex_t(int itohex, int caps);
void    flagmuncher(char type, va_list args, t_flag *flg, int *flenght);
void    ft_resolve_string(char *cad, t_flag *flg, int *flenght);
void    ft_resolve_pointer(char *cad, t_flag *flg, int *flenght);
void    ft_resolve_hex(char *cad, t_flag *flg, int *flenght);
void    ft_resolve_char(int n, t_flag *flg, int *flenght);
void    ft_resolve_pct(char pct, t_flag *flg, int *flenght);

#endif
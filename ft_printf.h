/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelgado <idelgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:48:58 by idelgado          #+#    #+#             */
/*   Updated: 2020/10/07 17:47:35 by idelgado         ###   ########.fr       */
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

char    *flaghandler(char *srcfrompercent, va_list args);
int ft_printf(const char *, ...);

#endif
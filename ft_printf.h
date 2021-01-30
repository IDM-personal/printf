/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelgado <idelgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:48:58 by idelgado          #+#    #+#             */
/*   Updated: 2021/01/30 20:15:50 by idelgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_flag
{
	char	type;
	int		zero;
	int		leftjust;
	int		width;
	int		precision;
	char	*content;
}				t_flag;

char			*flaghandler(char *srcfrompercent, va_list args, int *len);
int				ft_printf(const char *src, ...);
char			*ft_replace(char *cad, char toreplace, char *replacer);
void			fw(char *cad, t_flag *flg);
char			*fww(char *wp, t_flag *flg, va_list args);
void			fwp(char *wp, t_flag *flg, va_list args);
void			findprec(char *cad, t_flag *flg);
void			findwp(char *wp, t_flag *flg, va_list args);
void			flm(char *mods, t_flag *flg, va_list args);
char			*ft_itohex_t(unsigned int itohex, int caps);
char			*ft_itohex_u(unsigned long itohex, int caps);
void			flagmuncher(va_list args, t_flag *flg, int *flenght);
void			ft_resolve_string(char *cad, t_flag *flg, int *flenght);
void			ft_resolve_pointer(char *cad, t_flag *flg, int *flenght);
void			ft_resolve_hex(char *cad, t_flag *flg, int *flenght);
void			ft_resolve_char(int n, t_flag *flg, int *flenght);
void			ft_resolve_pct(char pct, t_flag *flg, int *flenght);
void			ft_resolve_i(int i, t_flag *flg, int *flenght);
void			ft_resolve_i_neg(char *cad, t_flag *flg, int *flenght);
void			ft_resolve_u(char *cad, t_flag *flg, int *flenght);
char			*ft_rev(char *src);
#endif

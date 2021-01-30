/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_formal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelgado <idelgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:53:18 by idm               #+#    #+#             */
/*   Updated: 2021/01/30 17:09:57 by idelgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flagsolve_i(va_list args, t_flag *flg, int *flenght)
{
	int	n;

	if (flg->type == 'u')
	{
		n = va_arg(args, unsigned int);
		if (!(n == 0 && flg->precision == 0 && flg->width <= 0))
			ft_resolve_u(ft_itoau(n), flg, flenght);
	}
	n = va_arg(args, int);
	if (n == 0 && flg->precision == 0 && flg->width <= 0)
		return ;
	if (flg->type == 'c')
		ft_resolve_char(n, flg, flenght);
	if (flg->type == 'x')
		ft_resolve_hex(ft_itohex_t(n, 0), flg, flenght);
	if (flg->type == 'X')
		ft_resolve_hex(ft_itohex_t(n, 1), flg, flenght);
	if (flg->type == 'i')
		ft_resolve_i(n, flg, flenght);
	if (flg->type == 'd')
		ft_resolve_i(n, flg, flenght);
}

void	flagmuncher(va_list args, t_flag *flg, int *flenght)
{
	char			*cad;
	unsigned long	val;

	if (flg->type == '%')
		ft_resolve_pct('%', flg, flenght);
	else if (flg->type == 's')
	{
		cad = va_arg(args, char*);
		if (cad == 0)
			cad = "(null)";
		ft_resolve_string(cad, flg, flenght);
	}
	else if (flg->type == 'p')
	{
		val = va_arg(args, unsigned long);
		if (val == 0 && flg->precision == 0 && flg->width <= 0)
			ft_putstr("0x", flenght);
		else
			ft_resolve_pointer(ft_itohex_u(val, 0), flg, flenght);
	}
	else
		flagsolve_i(args, flg, flenght);
}

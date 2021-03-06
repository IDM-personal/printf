/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idm <idm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 00:32:44 by idm               #+#    #+#             */
/*   Updated: 2021/01/12 21:25:53 by idm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_n(char *s, int max)
{
	int c;

	c = 0;
	if (s)
		while (*s && c !=max)
		{
			write(1, &(*s++), 1);
			c++;
		}
}
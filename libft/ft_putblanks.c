/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putblanks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idm <idm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 00:32:44 by idm               #+#    #+#             */
/*   Updated: 2021/01/12 00:59:15 by idm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putblanks(int max)
{
	int c;

	c = 0;
	while (c !=max)
	{
		write(1, " ", 1);
		c++;
	}
}
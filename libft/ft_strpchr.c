/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idm <idm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:38:08 by idelgado          #+#    #+#             */
/*   Updated: 2021/01/13 21:39:27 by idm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strpchr(const char *str, int c)
{
	int		ch;
	int		i;
	char	*cstr;

	cstr = (char*)str;
	i = 0;
	ch = c;
	while (cstr[i] != 0)
	{
		if (cstr[i] == ch)
			return (i);
		i++;
	}
	if (cstr[i] == ch)
		return (i);
	return (-1);
}

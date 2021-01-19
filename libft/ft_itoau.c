/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoau.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 05:57:42 by idelgado          #+#    #+#             */
/*   Updated: 2021/01/19 20:56:34 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*nbrlen(long n)
{
	int		res;
	char	*cad;

	res = 0;
	if (n < 0)
	{
		res++;
		n *= -1;
	}
	while (n / 10 > 0)
	{
		res++;
		n = n / 10;
	}
	if (!(cad = (char*)ft_calloc(1, res + 2)))
		return (NULL);
	return (cad);
}

static char		*ft_rev(char *cad)
{
	int		i;
	char	sv;
	int		len;

	len = ft_strlen(cad);
	i = 0;
	while (i < (len / 2))
	{
		sv = cad[i];
		cad[i] = cad[len - i - 1];
		cad[len - i - 1] = sv;
		i++;
	}
	return (cad);
}

char			*ft_itoau(unsigned int n)
{
	char			*cad;
	int				i;

	i = 0;
	if (!(cad = nbrlen((n))))
		return (NULL);
	while (n / 10 > 0)
	{
		cad[i++] = (n % 10) + '0';
		n = n / 10;
	}
	cad[i++] = n + '0';
	return (ft_rev(cad));
}

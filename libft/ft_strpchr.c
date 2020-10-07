/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelgado <idelgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:38:08 by idelgado          #+#    #+#             */
/*   Updated: 2020/10/07 19:12:41 by idelgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (0);
}

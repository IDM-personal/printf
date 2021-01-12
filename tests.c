/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelgado <idelgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:55:29 by idelgado          #+#    #+#             */
/*   Updated: 2020/12/01 11:32:56 by idelgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	printf("TAMANO = %i\n",printf("%2.5s\n","123456789"));
	printf("TAMANO = %i\n",printf("%0s\n","123456789"));
	printf("TAMANO = %i\n",printf("%-s\n","123456789"));
	printf("TAMANO = %i\n",printf("%0.0s\n","123456789"));
	printf("TAMANO = %i\n",printf("%0.5s\n","123456789"));
	printf("TAMANO = %i\n",printf("%5.0s\n","123456789"));
	printf("TAMANO = %i\n",printf("%1.1s\n","123456789"));
	printf("TAMANO = %i\n",printf("%-0s\n","123456789"));
	printf("TAMANO = %i\n",printf("%-1.1s\n","123456789"));
	printf("TAMANO = %i\n",printf("%-1.5s\n","123456789"));
}

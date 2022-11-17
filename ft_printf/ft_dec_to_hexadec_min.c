/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hexadec_min.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:51:30 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/17 16:04:21 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dec_to_hexadec_min(int i)
{
	int	n;
	char	hexadec[100];
	int	j;
	int	k;

	j = 0;
	while (i != 0)
	{
		n = i % 16;
		if (n < 10)
			hexadec[j++] = n + 48;
		else
			hexadec[j++] = n + 87; //97 - 10 in ascci
		i = i / 16;
	}
	k = j - 1;
	while (k >= 0)
	{
		ft_putchar(hexadec[k]);
		k--;
	}
	return (j);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_maj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:42:52 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/17 15:42:30 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_maj(const char *s, int ind, va_list args)
{
	int	i;

	i = va_arg(args, unsigned int);
	return (ft_dec_to_hexadec_maj(i));
}
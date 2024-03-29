/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:57:27 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/09 10:49:46 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// memmove - copy when there is an overlap

/* 
char src[30] = "012345678";
char *dst = src + 4;
memmove(dst, src, 6);
print dst
output 012345
*/

// general idea of copying: if dst is on the right, we go down, if dst is on the left, we go up

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*destin;
	char	*source;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	destin = (char *)dst;
	source = (char *)src;
	if (destin > source) //destin is on the right
	{
		while (len-- > 0) //the same as put len -- after destin[len] = source[len]
			destin[len] = source[len];
	}
	else 
	{
		while (i < len)
		{
			destin[i] = source[i];
			i++;
		}
	}
	return (destin);
}
/*
	char	*destin;
	char	*source;
	char	temp[len];  this doesn't pass la norminette
	size_t	i;

	i = 0;
	source = (char *)src;
	destin = dst;
	while (i < len)
	{
		temp[i] = source[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		destin[i] = temp[i];
		i++;
	}
	return (destin);
}
*/

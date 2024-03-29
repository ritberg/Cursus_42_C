/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:58:10 by mmakarov          #+#    #+#             */
/*   Updated: 2023/01/03 15:52:25 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//print struct
void	printlist(t_list *head)
{
	t_list	*temporary = head;

	printf("%s\n", "Pile A");
	while (temporary != NULL)
	{
		printf("%d\n", temporary->content);
		temporary = temporary->next;
	}
	if (temporary == NULL)
		printf("vide\n");
}

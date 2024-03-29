/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:20:08 by mmakarov          #+#    #+#             */
/*   Updated: 2023/01/03 17:13:40 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_index(t_list *pile) //find max and give an index to it (from 1)
{
	int	max;
	int	j;
	int	index;

	j = 1;
	max = -2147483648;
	while (pile != NULL)
	{
		if (pile->content > max) //if an elem of pile_a > max
		{
			max = pile->content; // it becomes max
			index = j;
		}
		pile = pile->next; //take next elem of pile_a
		j++;
	}
	return (index);
}

static	void	commands2(t_list ***pile_b, int middle, int index, int size)
{
	int	count;

	count = 1;
	if (middle > index)
	{
		while (count < index)
		{
			**pile_b = ra_rb(**pile_b, size, 'b'); //all commands several times
			count++;               //pile_a = .. - save modified param pile_a
		}
	}
	else
	{
		while (count <= size - index + 1)
		{
			**pile_b = rra_rrb(**pile_b, size, 'b');
			count++;
		}
	}
}

void	small_sort_r(t_list **pile_a, t_list **pile_b, int direction) //modify addresses? 
{
	int	middle;
	int	index;
	int	size;

	size = ft_lstsize(*pile_b);
	while (size > 3)
	{
		middle = size / 2;
		if (direction == MAX_TO_MIN)
			index = max_index(*pile_b);
		commands2(&pile_b, middle, index, size);
		pa(pile_a, pile_b);
		size--; //size decreases -1 after each while loop
	}
	//printlist(*pile_a);
	//printlist(*pile_b);
	*pile_b = very_small_sort_r(*pile_b);
	while (*pile_b != NULL)
		pa(pile_a, pile_b);
}

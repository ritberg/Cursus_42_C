/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_very_small_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:40:20 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/28 13:38:23 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* before I called functions-commands sa_sb, rra_rrb etc.
   now I have returns of these functions-commands 
   otherwise I loose the modified param pile_a
*/
static	t_list	*commands1(t_list *pile_b)
{
	t_list	*temp;

	temp = sa_sb(pile_b, 3, 'b');
	return (rra_rrb(temp, 3, 'b'));
}

static	t_list	*commands2(t_list *pile_b)
{
	t_list	*temp;

	temp = sa_sb(pile_b, 3, 'b');
	return (ra_rb(temp, 3, 'b'));
}

t_list	*test_very_small_sort(t_list *pile_b)
{
	t_list	*f;//first n
	t_list	*s;//second n
	t_list	*t;//third n

	f = pile_b;
	s = pile_b->next;
	t = s->next;
	if (f->content > s->content && s->content < t->content \
			&& t->content > f->content)
		return (sa_sb(pile_b, 3, 'b'));
	else if (f->content > s->content && s->content > t->content \
			&& f->content > t->content)
		return (commands1(pile_b));
	else if (f->content > s->content && s->content < t->content \
			&& f-> content > t->content)
		return (ra_rb(pile_b, 3, 'b'));
	else if (f->content < s->content && s->content > t->content \
			&& t->content > f->content)
		return (commands2(pile_b));
	else if (f->content < s->content && s->content > t->content \
			&& t->content < f->content)
		return (rra_rrb(pile_b, 3, 'b'));
	else
		return (pile_b);
}

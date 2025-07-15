/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:18:45 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/15 19:56:37 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	chunk_init(t_stack *a, t_stack *b)
{
	t_ps ps;
	t_chunk	all;

	ps.a = a;
	ps.b = b;
	all.loc = TOP_A;
	all.size = ps.a->size;
	divide_recursive(&ps, &all);
}

static void	dest_size_init(t_split_dest *dest)
{
	dest->max.size = 0;
	dest->mid.size = 0;
	dest->min.size = 0;
}

static void	dest_loc_init(t_split_dest *dest, t_chunk *to_sort)
{
	if (to_sort->loc == TOP_A)
	{
		dest->max.loc = BOTTOM_A;
		dest->mid.loc = TOP_B;
		dest->min.loc = BOTTOM_B;
	}
	else if (to_sort->loc == BOTTOM_A)
	{
		dest->max.loc = TOP_A;
		dest->mid.loc = TOP_B;
		dest->min.loc = BOTTOM_B;
	}
	else if (to_sort->loc == TOP_B)
	{
		dest->max.loc = TOP_A;
		dest->mid.loc = BOTTOM_A;
		dest->min.loc = BOTTOM_B;
	}
	else if (to_sort->loc == BOTTOM_B)
	{
		dest->max.loc = TOP_A;
		dest->mid.loc = BOTTOM_A;
		dest->min.loc = TOP_B;
	}
}

t_node	*get_right_node(t_ps *ps, t_location loc)
{
	if (loc == TOP_A)
		return (ps->a->top);
	else if (loc == BOTTOM_A)
		return (ps->a->bottom);
	else if (loc == TOP_B)
		return (ps->b->top);
	else
		return (ps->b->bottom);	
}

void	chunk_divide(t_ps *ps, t_split_dest *dest, t_chunk *to_sort)
{
	int		n;
	int		val;
	int		tier1;
	int		tier2;
	t_node	*cur;

	n = ps->a->size / 3;
	tier1 = n;
	tier2 = n * 2;
	n = 0;
	dest_size_init(dest);
	dest_loc_init(dest, to_sort);
	while (n < to_sort->size)
	{
		cur = get_right_node(ps, to_sort->loc);
		val = cur->nvalue;
		if (val < tier1)
		{
			split_from_to(ps, to_sort->loc, dest->min.loc);
			dest->min.size++;
		}
		else if (val <= tier2)
		{
			split_from_to(ps, to_sort->loc, dest->mid.loc);
			dest->mid.size++;
		}
		else if (val > tier2)
		{
			split_from_to(ps, to_sort->loc, dest->max.loc);
			dest->max.size++;
		}
		n++;
	}
}

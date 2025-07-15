/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_from_to.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:26:14 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/15 16:16:22 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	from_top_a(t_ps *ps, t_location to)
{
	if (to == BOTTOM_A)
	{
		ra(ps->a);
	}
	else if (to == TOP_B)
	{
		pb(ps->a, ps->b);
	}
	else if (to == BOTTOM_B)
	{
		pb(ps->a, ps->b);
		rb(ps->b);
	}
}

static void	from_top_b(t_ps *ps, t_location to)
{
	if (to == BOTTOM_B)
	{
		rb(ps->b);
	}
	else if (to == TOP_A)
	{
		pa(ps->b, ps->a);
	}
	else if (to == BOTTOM_A)
	{
		pa(ps->b, ps->a);
		ra(ps->a);
	}
}

void	split_from_to(t_ps *ps, t_location from, t_location to)
{
	if (from == TOP_A)
	{
		from_top_a(ps, to);
	}
	else if (from == BOTTOM_A)
	{
		rra(ps->a);
		split_from_to(ps, TOP_A, to);
	}
	else if (from == TOP_B)
	{
		from_top_b(ps, to);
	}
	else if (from == BOTTOM_B)
	{
		rrb(ps->b);
		split_from_to(ps, TOP_B, to);
	}
}

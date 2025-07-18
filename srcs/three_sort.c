/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 21:13:10 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/15 20:00:51 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_node *three_chunk_max_val_suite(t_ps *ps, t_chunk *chunk)
{
	int		i;
	t_node	*max;
	t_node	*cur;
	t_stack	*stack;

	i = 3;
	if (chunk->loc == BOTTOM_A)
		stack = ps->a;
	else
		stack = ps->b;
	cur = stack->bottom;
	max = cur;
	while (--i > 0)
	{
		if (cur->prev->nvalue > max->nvalue)
			max = cur->prev;
		cur = cur->prev;
	}
	return (max);
}

t_node	*three_chunk_max_val(t_ps *ps, t_chunk *chunk)
{
	int		i;
	t_node	*cur;
	t_node	*max;
	t_stack	*stack;

	i = 3;
	if (chunk->loc == TOP_A || chunk->loc == TOP_B)
	{
		if (chunk->loc == TOP_A)
			stack = ps->a;
		else
			stack = ps->b;
		cur = stack->top;
		max = cur;
		while (--i > 0)
		{
			if (cur->next->nvalue > max->nvalue)
				max = cur->next;
			cur = cur->next;
		}
	}
	else
		max = three_chunk_max_val_suite(ps, chunk);
	return (max);
}

static void	from_top_a(t_ps *ps, t_node *max)
{
	if (ps->a->top == max)
	{
		sa(ps->a);
		ra(ps->a);
		sa(ps->a);
		rra(ps->a);
	}
	else if (ps->a->top->next == max)
	{
		ra(ps->a);
		sa(ps->a);
		rra(ps->a);
	}
	if (ps->a->top->nvalue > ps->a->top->next->nvalue)
			sa(ps->a);
}

static void	from_bot_a(t_ps *ps, t_node *max)
{
	rra(ps->a);
	if (ps->a->bottom == max)
	{
		rra(ps->a);
		sa(ps->a);
		rra(ps->a);
	}
	else if (ps->a->bottom->prev == max)
	{
		rra(ps->a);
		rra(ps->a);
		sa(ps->a);
		ra(ps->a);
		sa(ps->a);
		rra(ps->a);
	}
	else
	{
		rra(ps->a);
		rra(ps->a);
	}
	if (ps->a->top->nvalue > ps->a->top->next->nvalue)
			sa(ps->a);
}

static void from_top_b(t_ps *ps, t_node *max)
{
	pa(ps->b, ps->a);
	if (ps->a->top == max)
	{
		pa(ps->b, ps->a);
		pa(ps->b, ps->a);
	}
	else if (ps->b->top == max)
	{
		pa(ps->b, ps->a);
		sa(ps->a);
		pa(ps->b, ps->a);
	}
	else
	{
		sb(ps->b);
		pa(ps->b, ps->a);
		sa(ps->a);
		pa(ps->b, ps->a);
	}
	if (ps->a->top->nvalue > ps->a->top->next->nvalue)
			sa(ps->a);
}

static void from_bot_b(t_ps *ps, t_node *max)
{
	split_from_to(ps, BOTTOM_B, TOP_A);
	rrb(ps->b);
	if (ps->b->bottom == max)
	{
		rrb(ps->b);
		pa(ps->b, ps->a);
		sa(ps->a);
		pa(ps->b, ps->a);
	}
	else if (ps->b->top == max)
	{
		pa(ps->b, ps->a);
		sa(ps->a);
		split_from_to(ps, BOTTOM_B, TOP_A);
	}
	else
	{
		pa(ps->b, ps->a);
		split_from_to(ps, BOTTOM_B, TOP_A);
	}
	if (ps->a->top->nvalue > ps->a->top->next->nvalue)
			sa(ps->a);
}

void	sort_three(t_ps *ps, t_chunk *to_sort)
{
	t_node	*max;

	max = three_chunk_max_val(ps, to_sort);
	if (to_sort->loc == TOP_A)
	{
		from_top_a(ps, max);
	}
	else if (to_sort->loc == BOTTOM_A)
	{
		from_bot_a(ps, max);
	}
	else if (to_sort->loc == TOP_B)
	{
		from_top_b(ps, max);
	}
	else if (to_sort->loc == BOTTOM_B)
	{
		from_bot_b(ps, max);
	}
}


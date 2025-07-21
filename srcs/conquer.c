/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conquer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:18:51 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/19 19:40:57 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_two(t_ps *ps, t_chunk *to_sort)
{
	if (to_sort->loc != TOP_A)
	{
		split_from_to(ps, to_sort->loc, TOP_A);
		split_from_to(ps, to_sort->loc, TOP_A);
	}
	if (ps->a->top->nvalue > ps->a->top->next->nvalue)
		sa(ps->a);
}

static void	chunk_sort_handler(t_ps *ps, t_chunk *to_sort)
{
	if (to_sort->size == 3)
	{
		sort_three(ps, to_sort);
		to_sort->size -= 3;
	}
	else if (to_sort->size == 2)
	{
		sort_two(ps, to_sort);
		to_sort->size -= 2;
	}
	else
	{
		if (to_sort->loc != TOP_A)
			split_from_to(ps, to_sort->loc, TOP_A);
		to_sort->size--;
	}
}

static void	divide_recursive(t_ps *ps, t_chunk *to_sort)
{
	t_split_dest	dest;

	if_alone_go_top(ps, to_sort);
	if (to_sort->size < 4)
	{
		chunk_sort_handler(ps, to_sort);
		return ;
	}
	chunk_divide(ps, &dest, to_sort);
	divide_recursive(ps, &dest.max);
	divide_recursive(ps, &dest.mid);
	divide_recursive(ps, &dest.min);
}

static void	stack_of_three(t_ps *ps)
{
	t_node	*top;

	top = ps->a->top;
	if (top->nvalue > top->next->nvalue
		&& top->nvalue > top->next->next->nvalue)
	{
		rra(ps->a);
		rra(ps->a);
	}
	else if (top->nvalue < top->next->nvalue
		&& top->next->nvalue > top->next->next->nvalue)
		rra(ps->a);
	if (ps->a->top->nvalue > ps->a->top->next->nvalue)
		sa(ps->a);
}

void	chunk_init(t_stack *a, t_stack *b)
{
	t_ps	ps;
	t_chunk	all;

	init_stack(b);
	ps.a = a;
	ps.b = b;
	all.loc = TOP_A;
	all.size = ps.a->size;
	if (a->size == 3)
	{
		stack_of_three(&ps);
		return ;
	}
	else if (a->size == 2)
	{
		if (a->top->nvalue > a->top->next->nvalue)
			sa(a);
	}
	divide_recursive(&ps, &all);
}

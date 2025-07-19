/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_&_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 23:30:14 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/18 23:30:27 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_node	*three_chunk_max_val_suite(t_ps *ps, t_chunk *chunk)
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

static int	get_chunk_lmin_suite(t_chunk *to_sort, t_node *cur,
		t_stack *stack)
{
	int	i;
	int	cur_min;

	i = 0;
	cur = stack->bottom;
	cur_min = cur->nvalue;
	while (++i < to_sort->size)
	{
		cur = cur->prev;
		if (cur_min > cur->nvalue)
			cur_min = cur->nvalue;
	}
	return (cur_min);
}

int	get_chunk_lmin(t_ps *ps, t_chunk *to_sort)
{
	int		i;
	int		cur_min;
	t_node	*cur;
	t_stack	*stack;

	i = 0;
	cur = NULL;
	if (to_sort->loc == TOP_A || to_sort->loc == BOTTOM_A)
		stack = ps->a;
	else
		stack = ps->b;
	if (to_sort->loc == TOP_A || to_sort->loc == TOP_B)
	{
		cur = stack->top;
		cur_min = cur->nvalue;
		while (++i < to_sort->size)
		{
			cur = cur->next;
			if (cur_min > cur->nvalue)
				cur_min = cur->nvalue;
		}
	}
	else
		cur_min = get_chunk_lmin_suite(to_sort, cur, stack);
	return (cur_min);
}

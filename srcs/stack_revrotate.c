/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_revrotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 04:20:42 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/07 04:22:41 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	last = stack->bottom;
	stack->bottom = last->prev;
	if (stack->bottom)
		stack->bottom->next = NULL;
	else
		stack->top = NULL;
	last->prev = NULL;
	last->next = stack->top;
	if (stack->top)
		stack->top->prev = last;
	stack->top = last;
	if (!stack->bottom)
		stack->bottom = last;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}

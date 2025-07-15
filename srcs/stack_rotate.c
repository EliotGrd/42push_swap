/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 04:14:46 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/07 04:17:57 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*first;

	if (!stack || stack->size < 2)
		return ;
	first = pop_top(stack);
	if (!first)
		return ;
	first->next = NULL;
	first->prev = stack->bottom;
	if (stack->bottom)
		stack->bottom->next = first;
	stack->bottom = first;
	if (!stack->top)
		stack->top = first;
	stack->size++;
}

void	ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

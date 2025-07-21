/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 04:08:28 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/15 16:15:50 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack *from, t_stack *to)
{
	t_node	*node;

	node = pop_top(from);
	if (node)
		push_top(to, node);
}

void	pa(t_stack *b, t_stack *a)
{
	push(b, a);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:34:24 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/20 04:20:16 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

int	fill_stack(t_stack *a, int *arr, int size)
{
	int		i;
	t_node	*cur;
	t_node	*new;

	i = size;
	while (--i >= 0)
	{
		new = create_node(arr[i]);
		if (!new)
			return (0);
		push_top(a, new);
	}
	shell_sort(arr, size);
	cur = a->top;
	while (cur)
	{
		i = -1;
		while (++i < size)
		{
			if (arr[i] == cur->value)
				cur->nvalue = i;
		}
		cur = cur->next;
	}
	return (1);
}


int	is_stack_sorted(t_stack *stack)
{
	t_node	*cur;

	cur = stack->top;
	while (cur)
	{
		if (cur->next)
		{
			if (cur->nvalue > cur->next->nvalue)
				return (0);
		}
		cur = cur->next;
	}
	return (1);
}

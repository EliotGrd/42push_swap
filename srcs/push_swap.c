/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:34:24 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/19 23:44:12 by egiraud          ###   ########.fr       */
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

void	check_duplicate(int *arr, int size, int *valid)
{
	int	i;
	int	j;

	i = 0;
	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				*valid = 0;
			j++;
		}
		i++;
	}
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

int	main(int ac, char **av)
{
	int		*arr;
	int		size;
	int		valid;
	t_stack	a;
	t_stack	b;

	size = 0;
	valid = 1;
	arr = parsing(ac, av, &size, &valid);
	if (valid)
		check_duplicate(arr, size, &valid);
	if (valid == 0)
	{
		write(1, "Error\n", 6);
		if (arr)
			free(arr);
		return (0);
	}
	init_stack(&a);
	valid = fill_stack(&a, arr, size);
	if (!is_stack_sorted(&a) && valid)
		chunk_init(&a, &b);
	free_stack(&a);
	free(arr);
	return (0);
}

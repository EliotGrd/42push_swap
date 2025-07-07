/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:34:24 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/07 04:59:59 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stack(t_stack *stack, const char *name)
{
	printf("Stack %s (size %d): ", name, stack->size);
	t_node *cur = stack->top;
	while (cur)
	{
		printf("%d ", cur->value);
		cur = cur->next;
	}
	printf("\n");
}

void init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

void	fill_stack(t_stack *a, int *arr, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		push_top(a, create_node(arr[i]));
		i--;
	}
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

int	main(int ac, char **av)
{
	int	*arr;
	int	size;
	int	valid;
	t_stack a;
	//t_stack b;

	size = 0;
	valid = 1;
	arr = parsing(ac, av, &size, &valid);
	check_duplicate(arr, size, &valid);
	if (valid == 0)
	{
		ft_printf("Error");
		if (arr)
			free(arr);
		return (0);
	}
	init_stack(&a);
	init_stack(&a);
	fill_stack(&a, arr, size);
	print_stack(&a, "a");
	//print_stack(&b, "b");
	return (0);
}

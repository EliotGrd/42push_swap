/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:34:24 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/15 19:49:23 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *stack, const char *name)
{
	t_node	*cur;

	printf("Stack %s (size %d):\n", name, stack->size);
	cur = stack->top;
	while (cur)
	{
		printf("%d ", cur->value);
		printf("at : %d\n", cur->nvalue);
		cur = cur->next;
	}
	printf("\n");
}

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

int	*shell_sort(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	gap;

	i = 0;
	gap = size / 2;
	while (gap > 0)
	{
		i = gap;
		while (i < size)
		{
			tmp = tab[i];
			j = i;
			while (j >= gap && tab[j - gap] > tmp)
			{
				tab[j] = tab[j - gap];
				j -= gap;
			}
			tab[j] = tmp;
			i++;
		}
		gap /= 2;
	}
	return (tab);
}

void	fill_stack(t_stack *a, int *arr, int size)
{
	int		i;
	t_node	*cur;

	i = size - 1;
	while (i >= 0)
	{
		push_top(a, create_node(arr[i]));
		i--;
	}
	shell_sort(arr, size);
	cur = a->top;
	while (cur)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == cur->value)
				cur->nvalue = i;
			i++;
		}
		cur = cur->next;
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

int	is_already_sorted(t_stack *stack)
{
	t_node	*cur;

	cur = stack->top;
	while (cur)
	{
		if (cur->next)
		{
			if (cur->nvalue > cur->next->nvalue)
			{
				return (0);
			}
		}
		cur = cur->next;
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_node	*cur;
	t_node	*next;

	if (!stack)
		return;
	cur = stack->top;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(cur);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
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
	check_duplicate(arr, size, &valid);
	if (valid == 0)
	{
		write(1, "Error\n", 6);
		if (arr)
			free(arr);
		return (0);
	}
	init_stack(&a);
	init_stack(&b);
	fill_stack(&a, arr, size);
	if (!is_already_sorted(&a))
		chunk_init(&a, &b);
	free_stack(&a);
	free(arr);
	return (0);
}


//verif avant de bouger si c pas deja trier
//adapter en combien split si besoin
//lister et opti
//
//va check ce quil se passe a partir de 9 3x3 check la condition darret

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 23:15:53 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/19 23:45:42 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	execute_cmds(char *line, t_stack *a, t_stack *b)
{
}

int	read_ops(t_stack *a, t_stack *b)
{
	char *line;

	while (line = get_next_line(0))
	{
		if (execute_cmds(line, a, b))
			error_h()
		free(line);
	}
}

void	check_and_res(t_stack *a, t_stack *b)
{
	int	b_is_empty;

	b_is_empty = 0;
	if (!b->top)
		b_is_empty = 1;
	if (is_stack_sorted(a) && b_is_empty)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
	fill_stack(&a, arr, size);
	init_stack(&b);
	read_ops(&a, &b);
	check_and_res(&a, &b);
}

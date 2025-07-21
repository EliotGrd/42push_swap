/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 23:15:53 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/21 01:15:38 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	execute_cmds(char *line, t_stack *a, t_stack *b)
{
	if (!(ft_strcmp(line, "sa\n")))
		return (sa(a), 1);
	if (!(ft_strcmp(line, "sb\n")))
		return (sb(b), 1);
	if (!(ft_strcmp(line, "ss\n")))
		return (ss(a, b), 1);
	if (!(ft_strcmp(line, "pa\n")))
		return (pa(b, a), 1);
	if (!(ft_strcmp(line, "pb\n")))
		return (pb(a, b), 1);
	if (!(ft_strcmp(line, "ra\n")))
		return (ra(a), 1);
	if (!(ft_strcmp(line, "rb\n")))
		return (rb(b), 1);
	if (!(ft_strcmp(line, "rr\n")))
		return (rr(a, b), 1);
	if (!(ft_strcmp(line, "rra\n")))
		return (rra(a), 1);
	if (!(ft_strcmp(line, "rrb\n")))
		return (rrb(b), 1);
	if (!(ft_strcmp(line, "rrr\n")))
		return (rrr(a, b), 1);
	return (0);
}

void	error_handler(char *line, t_stack *a, t_stack *b)
{
	free(line);
	if (a->top)
		free_stack(a);
	if (b->top)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(0);
}

void	read_ops(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!execute_cmds(line, a, b))
			error_handler(line, a, b);
		free(line);
		line = get_next_line(0);
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
	if (a->top)
		free_stack(a);
	if (b->top)
		free_stack(b);
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
	free(arr);
}

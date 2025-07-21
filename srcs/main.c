/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 04:19:51 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/20 04:20:09 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		write(2, "Error\n", 6);
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

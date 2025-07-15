/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conquer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:18:51 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/15 19:59:24 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_ps *ps, t_chunk *to_sort)
{
	if (to_sort->loc != TOP_A)
	{
		split_from_to(ps, to_sort->loc, TOP_A);
		split_from_to(ps, to_sort->loc, TOP_A);
	}
	if (ps->a->top > ps->a->top->next)
		sa(ps->a);
}

void	divide_recursive(t_ps *ps, t_chunk *to_sort)
{
	t_split_dest	dest;

	if (to_sort->size < 4)
	{
		if (to_sort->size == 3)
		{
			sort_three(ps, to_sort);
			to_sort->size -= 3;
		}
		else if (to_sort->size == 2)
		{
			sort_two(ps, to_sort);
			to_sort->size -= 2;
		}
		else
		{
			if (to_sort->loc != TOP_A)
				split_from_to(ps, to_sort->loc, TOP_A);
			to_sort->size--;
		}
		return;
	}
	//if size positive
	chunk_divide(ps, &dest, to_sort);
	divide_recursive(ps, &dest.max);
	divide_recursive(ps, &dest.mid);
	divide_recursive(ps, &dest.min);
}

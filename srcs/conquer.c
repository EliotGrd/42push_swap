/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conquer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:18:51 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/16 23:08:25 by egiraud          ###   ########.fr       */
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
	if (ps->a->top->nvalue > ps->a->top->next->nvalue)
		sa(ps->a);
}

void	divide_recursive(t_ps *ps, t_chunk *to_sort)
{
	t_split_dest	dest;

	if_alone_go_top(ps, to_sort);
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
		else //if (to_sort->size == 1)
		{
			if (to_sort->loc != TOP_A)
				split_from_to(ps, to_sort->loc, TOP_A);
			to_sort->size--;
		}
		return;
	}
	chunk_divide(ps, &dest, to_sort);
	divide_recursive(ps, &dest.max);
	divide_recursive(ps, &dest.mid);
	divide_recursive(ps, &dest.min);
}

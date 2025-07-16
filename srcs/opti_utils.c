/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:34:19 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/16 23:18:16 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	if_alone_go_top(t_ps *ps, t_chunk *to_sort)
{
	if (to_sort->loc == BOTTOM_B && to_sort->size == get_stack_size(ps->b))
		to_sort->loc = TOP_B;
	else if (to_sort->loc == BOTTOM_A && to_sort->size == get_stack_size(ps->a))
		to_sort->loc = TOP_A;
}

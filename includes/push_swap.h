/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:29:41 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/07 04:58:25 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/includes/libft.h"
#include <stdlib.h>

typedef struct s_node {
	int		value;
	struct s_node	*next;
	struct s_node	*prev;
}			t_node;


typedef struct s_stack {
	t_node	*top;
	t_node	*bottom;
	int		size;
}			t_stack;

/* MISC */
int	*parsing(int ac, char **av, int *size, int *valid);

/* STACK */

t_node	*create_node(int value);
void	push_top(t_stack *stack, t_node *node);
t_node	*pop_top(t_stack *stack);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif

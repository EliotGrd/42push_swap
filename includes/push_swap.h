/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:29:41 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/19 23:44:29 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				nvalue;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

typedef enum e_location
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
}					t_location;

typedef struct s_chunk
{
	t_location		loc;
	int				size;
}					t_chunk;

typedef struct s_split_dest
{
	t_chunk			min;
	t_chunk			mid;
	t_chunk			max;
}					t_split_dest;

typedef struct s_ps
{
	t_stack			*a;
	t_stack			*b;
}					t_ps;

/* MISC */
int					*parsing(int ac, char **av, int *size, int *valid);
void				chunk_init(t_stack *a, t_stack *b);
int					get_chunk_lmin(t_ps *ps, t_chunk *to_sort);
int					ft_atoi_safe(const char *nptr, int *valid);
void				split_free(char **arr);
int					*shell_sort(int *tab, int size);
t_node				*three_chunk_max_val(t_ps *ps, t_chunk *chunk);
void				check_duplicate(int *arr, int size, int *valid);

/* SORT */
void				split_from_to(t_ps *ps, t_location from, t_location to);
void				sort_three(t_ps *ps, t_chunk *to_sort);
void				chunk_divide(t_ps *ps, t_split_dest *dest,
						t_chunk *to_sort);

/* OPTI */
void				if_alone_go_top(t_ps *ps, t_chunk *to_sort);

/* STACK */

t_node				*create_node(int value);
void				push_top(t_stack *stack, t_node *node);
t_node				*pop_top(t_stack *stack);
int					get_stack_size(t_stack *stack);
void				free_stack(t_stack *stack);
void				init_stack(t_stack *stack);
int					fill_stack(t_stack *a, int *arr, int size);
int					is_stack_sorted(t_stack *stack);

void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);

void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

#endif

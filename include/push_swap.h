/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:58:57 by ego               #+#    #+#             */
/*   Updated: 2024/12/13 04:38:55 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# define ERROR "\033[31mError\033[0m\n"
# define CHUNK 20

typedef struct s_stack
{
	int				value;
	int				rank;
	struct s_stack	*next;
}	t_stack;

typedef struct s_bounds
{
	int	lower;
	int	upper;
	int	size;
}	t_bounds;

// Stack utilities
t_stack	*stack_new(int value);
t_stack	*stack_fill(char **argv);
void	stack_free(t_stack **stack);
int		stack_issorted(t_stack *stack);
int		stack_size(t_stack *stack);

// Operations
void	sa(t_stack **stack_a, int display);
void	sb(t_stack **stack_b, int display);
void	ss(t_stack **stack_a, t_stack **stack_b, int display);
void	pa(t_stack **stack_a, t_stack **stack_b, int display);
void	pb(t_stack **stack_a, t_stack **stack_b, int display);
void	ra(t_stack **stack_a, int display);
void	rb(t_stack **stack_b, int display);
void	rr(t_stack **stack_a, t_stack **stack_b, int display);
void	rra(t_stack **stack_a, int display);
void	rrb(t_stack **stack_b, int display);
void	rrr(t_stack **stack_a, t_stack **stack_b, int display);

// Sorting functions
void	small_sort(t_stack **stack_a, t_stack **stack_b, int size);
void	sort(t_stack **stack_a, t_stack **stack_b);

// Sorting utilities
void	compute_ranks(t_stack **stack);
int		get_min_index(t_stack *stack);
void	init_boundaries(t_bounds *bounds, int size);
void	update_boundaries(t_bounds *bounds);

// Display utilities
void	ft_putstr(char *str);
void	ft_putstr_error(char *s);
void	stack_print(t_stack *stack_a, t_stack *stack_b);

// Argument checking
int		check_argument(char **argv);

// Utilities
void	exit_error(t_stack **stack_a, t_stack **stack_b);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *nptr);

#endif
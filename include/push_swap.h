/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:58:57 by ego               #+#    #+#             */
/*   Updated: 2025/11/30 20:10:48 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define ERROR "\033[31mError\033[0m\n"
# define MOVE_WEIGHT 3
# define RANK_WEIGHT 2

typedef struct s_stack
{
	int				value;
	int				rank;
	int				cost_a;
	int				cost_b;
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
void	sort(t_stack **stack_a, t_stack **stack_b, int chunk);

// Sorting utilities
void	compute_ranks(t_stack **stack);
int		get_min_index(t_stack *stack);
int		get_rank_index(t_stack *stack, int rank);
int		get_target_index(t_stack *stack, int rank);
void	shift_stack(t_stack **stack, int rank, char s);
void	init_boundaries(t_bounds *bounds, int size, int chunk);
void	update_boundaries(t_bounds *bounds, int chunk);
void	calculate_costs(t_stack *a, t_stack *b);
void	move_least_cost_item(t_stack **a, t_stack **b);

// Display utilities
void	ft_putstr(char *str);
void	ft_putstr_error(char *str);

// Argument checking
int		check_argument(int argc, char **argv);

// Utilities
void	exit_error(t_stack **stack_a, t_stack **stack_b);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *nptr);
int		ft_abs(int n);
int		ft_max(int x, int y);

#endif
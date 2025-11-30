/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:05:19 by ego               #+#    #+#             */
/*   Updated: 2024/12/17 03:16:25 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Computes move costs for each element of stack B.
 *
 * @param a Stack A (target).
 * @param b Stack B (source).
 */
void	calculate_costs(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;
	int	index;

	size_a = stack_size(a);
	size_b = stack_size(b);
	index = 0;
	while (b)
	{
		b->cost_a = get_target_index(a, b->rank);
		if (b->cost_a >= size_a / 2 && b->cost_a > 0)
			b->cost_a -= size_a;
		b->cost_b = index;
		if (b->cost_b >= size_b / 2 && b->cost_b > 0)
			b->cost_b -= size_b;
		b = b->next;
		index++;
	}
	return ;
}

/**
 * @brief Finds the maximum rank value in stack B.
 *
 * @param b Stack B.
 *
 * @return Highest rank.
 */
static int	max_rank(t_stack *b)
{
	int	max_rank;

	max_rank = b->rank;
	while (b)
	{
		if (b->rank > max_rank)
			max_rank = b->rank;
		b = b->next;
	}
	return (max_rank);
}

/**
 * @brief Computes the effective cost of moving an item from B to A.
 *
 * When costs share the same sign, overlapping rotations reduce the total
 * operations needed.
 *
 * @param b Stack B.
 * @param rank Rank of the current node.
 * @param cost_a Rotational cost on stack A.
 * @param cost_b Rotational cost on stack B.
 *
 * @return Weighted effective cost.
 */
static int	get_effective_cost(t_stack *b, int rank, int cost_a, int cost_b)
{
	int	move_penalty;
	int	rank_penalty;

	if (cost_a * cost_b > 0)
		move_penalty = ft_max(ft_abs(cost_a), ft_abs(cost_b));
	else
		move_penalty = ft_abs(cost_a) + ft_abs(cost_b);
	rank_penalty = ft_abs(max_rank(b) - rank);
	return (MOVE_WEIGHT * move_penalty + RANK_WEIGHT * rank_penalty);
}

/**
 * @brief Applies combined rotations to reduce move cost.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 * @param cost_a Pending rotations for A.
 * @param cost_b Pending rotations for B.
 */
static void	double_shift(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b, 1);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b, 1);
		cost_a--;
		cost_b--;
	}
	while (++cost_a <= 0)
		rra(a, 1);
	while (--cost_a >= 1)
		ra(a, 1);
	while (++cost_b <= 0)
		rrb(b, 1);
	while (--cost_b >= 1)
		rb(b, 1);
}

/**
 * @brief Rotates stacks to bring the least-cost item from B to the top.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 */
void	move_least_cost_item(t_stack **a, t_stack **b)
{
	t_stack		*s;
	int			min_cost;
	int			effective_cost;
	int			cost_a;
	int			cost_b;

	s = *b;
	min_cost = INT_MAX;
	while (s)
	{
		effective_cost = get_effective_cost(*b, s->rank, s->cost_a, s->cost_b);
		if (effective_cost < min_cost)
		{
			cost_a = s->cost_a;
			cost_b = s->cost_b;
			min_cost = effective_cost;
		}
		s = s->next;
	}
	double_shift(a, b, cost_a, cost_b);
}

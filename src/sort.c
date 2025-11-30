/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:09:26 by ego               #+#    #+#             */
/*   Updated: 2024/12/17 03:33:31 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Pushes all elements from A to B except three, chunk by rank.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 * @param chunk Chunk divisor controlling batch size.
 */
static void	push_all(t_stack **a, t_stack **b, int chunk)
{
	int			remaining;
	int			pushed;
	t_bounds	bounds;

	init_boundaries(&bounds, stack_size(*a), chunk);
	remaining = bounds.size;
	while (remaining > 3)
	{
		pushed = 0;
		while (remaining > 3 && pushed < bounds.upper - bounds.lower)
		{
			if ((*a)->rank >= bounds.lower && (*a)->rank < bounds.upper)
			{
				pb(a, b, 1);
				pushed++;
				remaining--;
			}
			else
				ra(a, 1);
		}
		update_boundaries(&bounds, chunk);
	}
	return ;
}

/**
 * @brief Pushes everything back from B to A using minimal rotations.
 *
 * Costs are recomputed before each move to pick the cheapest candidate.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 */
static void	push_back(t_stack **a, t_stack **b)
{
	while (*b)
	{
		calculate_costs(*a, *b);
		move_least_cost_item(a, b);
		pa(a, b, 1);
	}
	return ;
}

/**
 * @brief Sorts stack A using a chunk-based push-swap strategy.
 *
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 * @param chunk Chunk divisor controlling batch size.
 */
void	sort(t_stack **stack_a, t_stack **stack_b, int chunk)
{
	compute_ranks(stack_a);
	push_all(stack_a, stack_b, chunk);
	small_sort(stack_a, stack_b, 3);
	push_back(stack_a, stack_b);
	shift_stack(stack_a, 0, 'a');
	return ;
}

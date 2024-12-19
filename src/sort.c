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

/*	push_all
*	Pushes everything from stack a to stack b except three. 
*	The push is made by smaller chunks rankwise.
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

/*	push_back
*	Pushes back everything from stack b to stack a.
*	Computes the cost of moving for each item of stack b.
*	Moves the least-cost item with minimum rotations.
*	Pushes said item and repeat operation until stack b is empty.
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

/*	sort
*	Sorts the stack a.
*	First pushes everything to b my smaller and smaller chunks.
*	Sorts the three elements left in a with small_sort.
*	Pushes back everything to a in right order with minimal moves.
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

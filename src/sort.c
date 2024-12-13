/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:09:26 by ego               #+#    #+#             */
/*   Updated: 2024/12/13 04:39:23 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ranks(t_stack *stack)
{
	while (stack)
	{
		printf("%i\n", stack->rank);
		stack = stack->next;
	}
	return ;
}

/*	push_all
*	Pushes everything from stack a to stack b except three. 
*	The push is made by smaller chunks rankwise.
*	Occasionally swaps values to sort by pairs in descending order.
*	Sorts stack a afterwards with sort_three.
*	Cost: at most 4n moves.
*/
static void	push_all(t_stack **a, t_stack **b)
{
	int			remaining;
	int			pushed;
	t_bounds	bounds;

	init_boundaries(&bounds, stack_size(*a));
	remaining = bounds.size;
	while (remaining > 3)
	{
		pushed = 0;
		while (remaining > 3 && pushed < bounds.upper - bounds.lower)
		{
			if ((*a)->rank >= bounds.lower && (*a)->rank < bounds.upper)
			{
				pb(a, b, 1);
				if ((*b)->next && (*b)->rank < (*b)->next->rank)
					sb(b, 1);
				pushed++;
				remaining--;
			}
			else
				ra(a, 1);
		}
		update_boundaries(&bounds);
	}
	small_sort(a, b, 3);
}

static void	push_back(t_stack **a, t_stack **b)
{
	while (*b)
		pa(a, b, 1);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	compute_ranks(stack_a);
	push_all(stack_a, stack_b);
	push_back(stack_a, stack_b);
	return ;
}

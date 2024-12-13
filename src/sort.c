/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:09:26 by ego               #+#    #+#             */
/*   Updated: 2024/12/13 16:58:57 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ranks(t_stack *s)
{
	while (s)
	{
		printf("%i\t:\t%i\n", s->rank, s->value);
		s = s->next;
	}
	return ;
}

/*	push_all
*	Pushes everything from stack a to stack b except three. 
*	The push is made by smaller chunks rankwise.
*	Occasionally swaps values to sort by pairs in descending order.
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
	return ;
}

static void	push_back(t_stack **a, t_stack **b)
{
	int	rank;

	rank = (*b)->rank;
	while (*b)
	{
		if ((*b)->rank == rank)
		{
			pa(a, b, 1);
			rank--;
		}
		else
			rb(b, 1);
	}
	return ;
}

/*	sort
*	Sorts the stack a.
*	First pushes everything to b my smaller and smaller chunks.
*	Sorts the three elements left in a with small_sort.
*	Pushes back everything to a in right order with minimal moves.
*/
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	compute_ranks(stack_a);
	push_all(stack_a, stack_b);
	small_sort(stack_a, stack_b, 3);
	push_back(stack_a, stack_b);
	return ;
}

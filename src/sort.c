/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:09:26 by ego               #+#    #+#             */
/*   Updated: 2024/12/15 02:58:38 by ego              ###   ########.fr       */
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
				if ((*b)->next && (*b)->rank < (*b)->next->rank)
					sb(b, 1);
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

int	get_rank_index(t_stack *s, int rank)
{
	int	index;

	index = 0;
	while (s)
	{
		if (s->rank == rank)
			return (index);
		index++;
		s = s->next;
	}
	return (-1);
}

static void	push_back(t_stack **a, t_stack **b)
{
	int	rank;
	int	size;
	int	index;

	rank = (*b)->rank;
	size = stack_size(*b);
	while (*b)
	{
		if ((*b)->rank == rank)
		{
			pa(a, b, 1);
			rank--;
			size--;
		}
		else
		{
			index = get_rank_index(*b, rank);
			if (index < size / 2)
			{
				while ((*b)->rank != rank)
					rb(b, 1);
			}
			else
			{
				while ((*b)->rank != rank)
					rrb(b, 1);
			}
		}
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
	return ;
}

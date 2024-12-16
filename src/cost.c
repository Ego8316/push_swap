/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:05:19 by ego               #+#    #+#             */
/*   Updated: 2024/12/16 23:40:22 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	calculate_costs
*	Computes the move cost for each item of stack b.
*	If position is in the first half of the stack,
*	cost is positive and negative otherwise.
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

/*	get_effective_cost
*	Computes the effective cost for moving an item from b to a.
*	Example: cost_a = -3 and cost_b = -5, the cost is actually 5 and
*	not 8 since three of the rotations can be performed on both stacks.
*	Return: effective cost.
*/
static int	get_effective_cost(int cost_a, int cost_b)
{
	if (cost_a * cost_b > 0)
		return (ft_max(ft_abs(cost_a), ft_abs(cost_b)));
	else
		return (ft_abs(cost_a) + ft_abs(cost_b));
}

/*	double_shift
*	Shifts both stacks using double rotations when possible.
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

/*	move_least_cost_item
*	Finds the least-cost item to bring to the top of stack b.
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
		effective_cost = get_effective_cost(s->cost_a, s->cost_b);
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

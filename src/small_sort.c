/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:11:27 by ego               #+#    #+#             */
/*   Updated: 2024/12/11 02:27:29 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	sort_three
*	Sorts the stack_a if it has size 3.
*/
void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (third > second && third > first)
		sa(stack_a, 1);
	else if (first < second && first < third)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (first > second && first > third && second > third)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (first > second && first > third && second < third)
		ra(stack_a, 1);
	else if (third < first && third < second && second > first)
		rra(stack_a, 1);
	return ;
}

/*	sort_four
Sorts the stack if it has size 4.
*/
void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min_index;

	min_index = get_min_index(*stack_a);

	if (min_index == 3)
		rra(stack_a, 1);
	else if (min_index == 2)
	{
		ra(stack_a, 1);
		sa(stack_a, 1);
	}
	else if (min_index == 1)
		sa(stack_a, 1);
	pb(stack_a, stack_b, 1);
	sort_three(stack_a);
	pa(stack_a, stack_b, 1);
	return ;
}

/*	sort_five
Sorts the stack if it has size 5.
*/
void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min_index;

	min_index = get_min_index(*stack_a);

	if (min_index == 4)
		rra(stack_a, 1);
	else if (min_index == 3)
	{
		rra(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (min_index == 2)
	{
		ra(stack_a, 1);
		sa(stack_a, 1);
	}
	else if (min_index == 1)
		sa(stack_a, 1);
	pb(stack_a, stack_b, 1);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b, 1);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:11:27 by ego               #+#    #+#             */
/*   Updated: 2024/12/13 15:49:24 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts stack A when it contains exactly three elements.
 *
 * @param stack_a Pointer to stack A.
 */
static void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (third > second && third > first && first > second)
		sa(stack_a, 1);
	else if (first < second && first < third && second > third)
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

/**
 * @brief Sorts stack A when it contains four elements.
 *
 * Moves the smallest value to B, sorts the remaining three, then restores it.
 *
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 */
static void	sort_four(t_stack **stack_a, t_stack **stack_b)
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

/**
 * @brief Sorts stack A when it contains five elements.
 *
 * Pushes the smallest value to B, sorts the remaining four, then restores it.
 *
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 */
static void	sort_five(t_stack **stack_a, t_stack **stack_b)
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

/**
 * @brief Sorts small stacks (size 3 to 5) with dedicated routines.
 *
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 * @param size Size of stack A.
 */
void	small_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:30:25 by ego               #+#    #+#             */
/*   Updated: 2024/12/20 14:38:13 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Assigns a rank to each node based on sorted order.
 *
 * @param stack Pointer to the stack head.
 */
void	compute_ranks(t_stack **stack)
{
	t_stack	*head;
	t_stack	*s;
	int		r;

	head = *stack;
	while (*stack)
	{
		s = head;
		r = 0;
		while (s)
		{
			if (s->value < (*stack)->value)
				r++;
			s = s->next;
		}
		(*stack)->rank = r;
		(*stack) = (*stack)->next;
	}
	*stack = head;
	return ;
}

/**
 * @brief Finds the index of the minimum value in the stack.
 *
 * @param stack Stack to inspect.
 *
 * @return Index of the smallest value.
 */
int	get_min_index(t_stack *stack)
{
	int	min;
	int	min_index;
	int	i;

	min = stack->value;
	min_index = 0;
	i = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_index = i;
		}
		i++;
		stack = stack->next;
	}
	return (min_index);
}

/**
 * @brief Finds the index of the node with a given rank.
 *
 * @param stack Stack to inspect.
 * @param rank Target rank.
 *
 * @return Index of the rank, -1 if not found.
 */
int	get_rank_index(t_stack *stack, int rank)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->rank == rank)
			return (index);
		index++;
		stack = stack->next;
	}
	return (-1);
}

/**
 * @brief Gets the index where a rank should be inserted in sorted order.
 *
 * @param stack Stack to inspect.
 * @param rank Rank to place.
 *
 * @return Target index for insertion.
 */
int	get_target_index(t_stack *stack, int rank)
{
	int	min_rank_index;
	int	index;
	int	target_rank;
	int	target_index;

	min_rank_index = get_min_index(stack);
	index = 0;
	target_index = -1;
	target_rank = INT_MAX;
	while (stack)
	{
		if (stack->rank > rank && stack->rank < target_rank)
		{
			target_index = index;
			target_rank = stack->rank;
		}
		index++;
		stack = stack->next;
	}
	if (target_index == -1)
		return (min_rank_index);
	else
		return (target_index);
}

/**
 * @brief Rotates a stack to bring the node with `rank` to the top.
 *
 * Chooses the direction with the fewest moves.
 *
 * @param stack Pointer to the stack.
 * @param rank Desired rank to bring up.
 * @param s Stack identifier ('a' or 'b') to pick the right rotation.
 */
void	shift_stack(t_stack **stack, int rank, char s)
{
	int	index;
	int	size;

	index = get_rank_index(*stack, rank);
	if (index == -1)
		return ;
	size = stack_size(*stack);
	if (index < size / 2)
	{
		while (s == 'a' && (*stack)->rank != rank)
			ra(stack, 1);
		while (s == 'b' && (*stack)->rank != rank)
			rb(stack, 1);
	}
	else
	{
		while (s == 'a' && (*stack)->rank != rank)
			rra(stack, 1);
		while (s == 'b' && (*stack)->rank != rank)
			rrb(stack, 1);
	}
	return ;
}

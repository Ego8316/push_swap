/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:30:25 by ego               #+#    #+#             */
/*   Updated: 2024/12/16 05:28:57 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	compute_ranks
*	Compute the sorted ranks for each value of the stack and assign them.
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

/*	get_min_index
*	Get the index of the minimum value of the stack.
*	Return: said index.
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

/*	get_rank_index
*	Gets the stack index corresponding to the asked rank.
*	Return: the desired index, -1 if not found.
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

/*	get_target_index
*	Gets the index where given rank should go in the current stack.
*	Return: said index
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

/*	shift_stack
*	Shifts the stack s to get desired rank to the top of the stack.
*	Finds the minimum moves between rotate and reverse rotate.
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

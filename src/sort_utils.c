/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:30:25 by ego               #+#    #+#             */
/*   Updated: 2024/12/13 03:32:56 by ego              ###   ########.fr       */
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

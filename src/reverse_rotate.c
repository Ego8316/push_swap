/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:09:34 by ego               #+#    #+#             */
/*   Updated: 2024/12/11 01:16:55 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Moves the last element of the stack to the top.
 *
 * @param stack Stack to rotate.
 */
static void	reverse_rotate(t_stack **stack)
{
	t_stack	*before_tail;
	t_stack	*tail;

	if (!(*stack) || !((*stack)->next))
		return ;
	before_tail = *stack;
	while (before_tail->next->next)
		before_tail = before_tail->next;
	tail = before_tail->next;
	before_tail->next = NULL;
	tail->next = *stack;
	*stack = tail;
}

/**
 * @brief Rotates stack A down by one.
 *
 * @param stack_a Pointer to stack A.
 * @param display Set to 1 to print the operation.
 */
void	rra(t_stack **stack_a, int display)
{
	reverse_rotate(stack_a);
	if (display)
		ft_putstr("rra\n");
	return ;
}

/**
 * @brief Rotates stack B down by one.
 *
 * @param stack_b Pointer to stack B.
 * @param display Set to 1 to print the operation.
 */
void	rrb(t_stack **stack_b, int display)
{
	reverse_rotate(stack_b);
	if (display)
		ft_putstr("rrb\n");
	return ;
}

/**
 * @brief Executes `rra` and `rrb` simultaneously.
 *
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 * @param display Set to 1 to print the operation.
 */
void	rrr(t_stack **stack_a, t_stack **stack_b, int display)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (display)
		ft_putstr("rrr\n");
	return ;
}

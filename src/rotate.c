/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:09:48 by ego               #+#    #+#             */
/*   Updated: 2024/12/11 01:17:05 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Moves the first element of the stack to the bottom.
 *
 * @param stack Stack to rotate.
 */
static void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;

	if (!(*stack) || !((*stack)->next))
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	temp->next = NULL;
	tail->next = temp;
}

/**
 * @brief Rotates stack A up by one.
 *
 * @param stack_a Pointer to stack A.
 * @param display Set to 1 to print the operation.
 */
void	ra(t_stack **stack_a, int display)
{
	rotate(stack_a);
	if (display)
		ft_putstr("ra\n");
	return ;
}

/**
 * @brief Rotates stack B up by one.
 *
 * @param stack_b Pointer to stack B.
 * @param display Set to 1 to print the operation.
 */
void	rb(t_stack **stack_b, int display)
{
	rotate(stack_b);
	if (display)
		ft_putstr("rb\n");
	return ;
}

/**
 * @brief Executes `ra` and `rb` simultaneously.
 *
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 * @param display Set to 1 to print the operation.
 */
void	rr(t_stack **stack_a, t_stack **stack_b, int display)
{
	rotate(stack_a);
	rotate(stack_b);
	if (display)
		ft_putstr("rr\n");
	return ;
}

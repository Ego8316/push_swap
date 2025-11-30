/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:04:19 by ego               #+#    #+#             */
/*   Updated: 2024/12/13 16:16:11 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swaps the first two elements of a stack.
 *
 * @param stack Stack to mutate.
 */
static void	swap(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->rank;
	stack->rank = stack->next->rank;
	stack->next->rank = temp;
	return ;
}

/**
 * @brief Swaps the first two elements of stack A.
 *
 * @param stack_a Pointer to stack A.
 * @param display Set to 1 to print the operation.
 */
void	sa(t_stack **stack_a, int display)
{
	swap(*stack_a);
	if (display)
		ft_putstr("sa\n");
	return ;
}

/**
 * @brief Swaps the first two elements of stack B.
 *
 * @param stack_b Pointer to stack B.
 * @param display Set to 1 to print the operation.
 */
void	sb(t_stack **stack_b, int display)
{
	swap(*stack_b);
	if (display)
		ft_putstr("sb\n");
	return ;
}

/**
 * @brief Executes `sa` and `sb` simultaneously.
 *
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 * @param display Set to 1 to print the operation.
 */
void	ss(t_stack **stack_a, t_stack **stack_b, int display)
{
	swap(*stack_a);
	swap(*stack_b);
	if (display)
		ft_putstr("ss\n");
	return ;
}

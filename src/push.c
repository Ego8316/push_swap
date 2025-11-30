/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:10:25 by ego               #+#    #+#             */
/*   Updated: 2024/12/11 01:17:39 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Moves the first element of `src` to the top of `dest`.
 *
 * @param src Pointer to the source stack.
 * @param dest Pointer to the destination stack.
 */
static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!(*src))
		return ;
	temp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = temp;
	return ;
}

/**
 * @brief Pushes the first element of stack B to stack A.
 *
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 * @param display Set to 1 to print the operation.
 */
void	pa(t_stack **stack_a, t_stack **stack_b, int display)
{
	push(stack_b, stack_a);
	if (display)
		ft_putstr("pa\n");
	return ;
}

/**
 * @brief Pushes the first element of stack A to stack B.
 *
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 * @param display Set to 1 to print the operation.
 */
void	pb(t_stack **stack_a, t_stack **stack_b, int display)
{
	push(stack_a, stack_b);
	if (display)
		ft_putstr("pb\n");
	return ;
}

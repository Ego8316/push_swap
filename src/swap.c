/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:04:19 by ego               #+#    #+#             */
/*   Updated: 2024/12/11 01:17:24 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	swap
*	Swaps the first two elements of stack.
*/
static void	swap(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	return ;
}

/*	sa
*	Swaps the first two elements of stack a.
*/
void	sa(t_stack **stack_a, int display)
{
	swap(*stack_a);
	if (display)
		ft_putstr("sa\n");
	return ;
}

/*	sa
*	Swaps the first two elements of stack b.
*/
void	sb(t_stack **stack_b, int display)
{
	swap(*stack_b);
	if (display)
		ft_putstr("sb\n");
	return ;
}

/*	ss
*	sa and sb at the same time.
*/
void	ss(t_stack **stack_a, t_stack **stack_b, int display)
{
	swap(*stack_a);
	swap(*stack_b);
	if (display)
		ft_putstr("ss\n");
	return ;
}

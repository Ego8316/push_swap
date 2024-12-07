/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:09:34 by ego               #+#    #+#             */
/*   Updated: 2024/12/07 19:42:28 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	reverse_rotate
*	The last element of the stack becomes the first one.
*/
static void	reverse_rotate(t_stack **stack)
{
	t_stack *before_tail;
	t_stack *tail;

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

/*	rra
*	The last element of stack a becomes the first one.
*/
void	rra(t_stack **stack_a, int display)
{
	reverse_rotate(stack_a);
	if (display)
		ft_putstr("rra\n");
	return ;
}

/*	rrb
*	The last element of stack b becomes the first one.
*/
void	rrb(t_stack **stack_b, int display)
{
	reverse_rotate(stack_b);
	if (display)
		ft_putstr("rrb\n");
	return ;
}

/*	rrr
*	The last elements of stacks a and b become the first ones.
*/
void	rrr(t_stack **stack_a, t_stack **stack_b, int display)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (display)
		ft_putstr("rrr\n");
	return ;
}
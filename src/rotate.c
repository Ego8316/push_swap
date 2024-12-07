/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:09:48 by ego               #+#    #+#             */
/*   Updated: 2024/12/07 19:52:10 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	rotate
*	The first element of the stack becomes the last one.
*/
static void	rotate(t_stack **stack)
{
	t_stack *temp;
	t_stack *tail;

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

/*	ra
*	The first element of stack a becomes the last one.
*/
void	ra(t_stack **stack_a, int display)
{
	rotate(stack_a);
	if (display)
		ft_putstr("ra\n");
	return ;
}

/*	rb
*	The first element of stack b becomes the last one.
*/
void	rb(t_stack **stack_b, int display)
{
	rotate(stack_b);
	if (display)
		ft_putstr("rb\n");
	return ;
}

/*	rr
*	ra and rb at the same time.
*/
void	rr(t_stack **stack_a, t_stack **stack_b, int display)
{
	rotate(stack_a);
	rotate(stack_b);
	if (display)
		ft_putstr("rr\n");
	return ;
}

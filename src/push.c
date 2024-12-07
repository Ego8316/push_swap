/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:10:25 by ego               #+#    #+#             */
/*   Updated: 2024/12/07 19:16:10 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	push
*	Pushes the first element of src to dest.
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

/*	pa
*	Pushes the first element of stack b to stack a.
*/
void	pa(t_stack **stack_a, t_stack **stack_b, int display)
{
	push(stack_b, stack_a);
	if (display)
		ft_putstr("pa\n");
	return ;
}

/*	pb
*	Pushes the first element of stack a to stack b.
*/
void	pb(t_stack **stack_a, t_stack **stack_b, int display)
{
	push(stack_a, stack_b);
	if (display)
		ft_putstr("pb\n");
	return ;
}
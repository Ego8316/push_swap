/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:30:25 by ego               #+#    #+#             */
/*   Updated: 2024/12/11 02:19:33 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_ranks(t_stack **stack)
{
	(*stack)->rank = 2;
	return ;
}

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

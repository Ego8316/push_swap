/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:21:53 by ego               #+#    #+#             */
/*   Updated: 2024/12/07 19:51:27 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// int	check_argument(int argc, char **argv)
// {
// 	return (1);
// }

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	if (argc < 2)
		return (0);
	if (!check_argument(argv))
		exit_error(0, 0);
	stack_a = stack_fill(argv);
	stack_b = NULL;
	stack_print(stack_a, stack_b);
	printf("------------------\n");
	sa(&stack_a, 1);
	stack_print(stack_a, stack_b);
	printf("------------------\n");
	pb(&stack_a, &stack_b, 1);
	pb(&stack_a, &stack_b, 1);
	pb(&stack_a, &stack_b, 1);
	stack_print(stack_a, stack_b);
	printf("------------------\n");
	ra(&stack_a, 1);
	rb(&stack_b, 1);
	stack_print(stack_a, stack_b);
	printf("------------------\n");
	rra(&stack_a, 1);
	rrb(&stack_b, 1);
	stack_print(stack_a, stack_b);
	printf("------------------\n");
	sa(&stack_a, 1);
	stack_print(stack_a, stack_b);
	printf("------------------\n");
	pa(&stack_a, &stack_b, 1);
	pa(&stack_a, &stack_b, 1);
	pa(&stack_a, &stack_b, 1);
	stack_print(stack_a, stack_b);
	printf(">%i\n", stack_issorted(stack_a));
	return (0);
}

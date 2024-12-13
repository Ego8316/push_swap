/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:21:53 by ego               #+#    #+#             */
/*   Updated: 2024/12/13 16:13:26 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (!check_argument(argv))
		exit_error(0, 0);
	stack_a = stack_fill(argv);
	stack_b = NULL;
	compute_ranks(&stack_a);
	if (!stack_issorted(stack_a))
	{
		if (argc < 4)
			sa(&stack_a, 1);
		else if (argc < 7)
			small_sort(&stack_a, &stack_b, argc - 1);
		else
			sort(&stack_a, &stack_b);
	}
	if (stack_issorted(stack_a))
		printf("OK\n");
	else
		printf("KO\n");
	stack_free(&stack_a);
	stack_free(&stack_b);
	return (0);
}

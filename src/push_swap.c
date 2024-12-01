/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:21:53 by ego               #+#    #+#             */
/*   Updated: 2024/12/01 07:03:55 by ego              ###   ########.fr       */
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
	// t_stack	*stack_a;
	// t_stack	*stack_b;

	if (argc < 2)
		return (0);
	printf(">%i\n", check_argument(argv));
	return (0);
}

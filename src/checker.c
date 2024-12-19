/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 07:32:19 by ego               #+#    #+#             */
/*   Updated: 2024/12/19 02:41:30 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>
#include <fcntl.h>

void	do_move(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp("sa\n", line))
		sa(a, 0);
	else if (!ft_strcmp("sb\n", line))
		sb(b, 0);
	else if (!ft_strcmp("ss\n", line))
		ss(a, b, 0);
	else if (!ft_strcmp("pa\n", line))
		pa(a, b, 0);
	else if (!ft_strcmp("pb\n", line))
		pb(a, b, 0);
	else if (!ft_strcmp("ra\n", line))
		ra(a, 0);
	else if (!ft_strcmp("rb\n", line))
		rb(b, 0);
	else if (!ft_strcmp("rr\n", line))
		rr(a, b, 0);
	else if (!ft_strcmp("rra\n", line))
		rra(a, 0);
	else if (!ft_strcmp("rrb\n", line))
		rrb(b, 0);
	else if (!ft_strcmp("rrr\n", line))
		rrr(a, b, 0);
	else
		exit_error(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (argc < 2)
		return (0);
	if (!check_argument(argc, argv))
		exit_error(0, 0);
	stack_a = stack_fill(argv);
	stack_b = NULL;
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		do_move(line, &stack_a, &stack_b);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (stack_issorted(stack_a) && !stack_b)
		ft_putstr(OK);
	else
		ft_putstr(KO);
	ft_free(&line);
	stack_free(&stack_a);
	stack_free(&stack_b);
	return (0);
}

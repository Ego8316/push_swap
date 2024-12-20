/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 07:32:19 by ego               #+#    #+#             */
/*   Updated: 2024/12/20 01:39:45 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*	do_move
*	Applies the move given by the line.
*	Return: 0 if the line does correspond to a move, 1 otherwise.
*/
static int	do_move(char *line, t_stack **a, t_stack **b)
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
		return (1);
	return (0);
}

/*	read_instructions
*	Reads line by line the standard input.
*	In case of error, sets error to one to indicate
*	an error occured (failed malloc or wrong instruction).
*	Return: 0 if everything went well, 1 otherwise.
*/
static int	read_instructions(t_stack **stack_a, t_stack **stack_b)
{
	int		error;
	char	*line;

	error = 0;
	line = get_next_line(STDIN_FILENO, &error);
	while (line)
	{
		if (!error)
			error = do_move(line, stack_a, stack_b);
		ft_free(&line);
		line = get_next_line(STDIN_FILENO, &error);
	}
	ft_free(&line);
	return (error);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (!check_argument(argc, argv))
		exit_error(0, 0);
	stack_a = stack_fill(argv);
	stack_b = NULL;
	if (read_instructions(&stack_a, &stack_b))
		exit_error(&stack_a, &stack_b);
	if (stack_issorted(stack_a) && !stack_b)
		ft_putstr(OK);
	else
		ft_putstr(KO);
	stack_free(&stack_a);
	stack_free(&stack_b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:29:49 by ego               #+#    #+#             */
/*   Updated: 2024/12/13 01:39:24 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	stack_new
*	Creates a new stack node.
*	Return: NULL if allocation failed, the new node otherwise.
*/
t_stack	*stack_new(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

/*	stack_free
*	Frees the whole stack.
*/
void	stack_free(t_stack **stack)
{
	t_stack	*s;
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	s = *stack;
	while (s)
	{
		temp = s->next;
		s->value = 0;
		s->next = NULL;
		free(s);
		s = temp;
	}
	*stack = NULL;
	return ;
}

/*	stack_fill
*	Creates a stack and fills it with the arguments.
*	Return: the filled stack, exits the program if allocation failed.
*/
t_stack	*stack_fill(char **argv)
{
	t_stack	*stack;
	t_stack	*node;
	int		i;

	stack = stack_new(ft_atoi(argv[1]));
	if (!stack)
		exit_error(0, 0);
	node = stack;
	i = 2;
	while (argv[i])
	{
		node->next = stack_new(ft_atoi(argv[i]));
		if (!(node->next))
			exit_error(&stack, 0);
		node = node->next;
		i++;
	}
	node->next = NULL;
	return (stack);
}

/*	stack_issorted
*	Checks if a stack is sorted.
*	Return: 1 if it is sorted, 0 otherwise.
*/
int	stack_issorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*	stack_size
*	Computes the size of a stack.
*	Return: said size.
*/
int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

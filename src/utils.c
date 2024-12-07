/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:31:11 by ego               #+#    #+#             */
/*   Updated: 2024/12/07 19:20:05 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	exit_error
*	Exits the program after freeing the stacks.
*/
void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	stack_free(stack_a);
	stack_free(stack_b);
	ft_putstr_error(ERROR);
	exit(1);
}

/*	ft_strcmp
*	Checks if the two given strings are identical.
*	Return: 1 if the strings differ, 0 otherwise.
*/
int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	diff;

	i = 0;
	while (s1[i] || s2[i])
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (diff)
			return (1);
		i++;
	}
	return (0);
}

/*	ft_isdigit
*	Checks if the given character is a digit.
*	Return: 1 if the character is a digit, 0 otherwise.
*/
int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/*	ft_atoi
*	Convers a string to an integer.
*	Return: the converted integer.
*/
int	ft_atoi(char *nptr)
{
	int	nb;
	int	i;
	int	sign;

	nb = 0;
	i = 0;
	sign = 1;
	if (!ft_strcmp(nptr, "-2147483648"))
		return (-2147483648);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		sign = 44 - nptr[i];
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}

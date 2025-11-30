/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:31:11 by ego               #+#    #+#             */
/*   Updated: 2024/12/17 17:32:43 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Frees stacks, prints an error, and exits the program.
 *
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 */
void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	stack_free(stack_a);
	stack_free(stack_b);
	ft_putstr_error(ERROR);
	exit(1);
}

/**
 * @brief Compares two strings for equality.
 *
 * @param s1 First string.
 * @param s2 Second string.
 *
 * @return 0 if identical, 1 otherwise.
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

/**
 * @brief Converts an ASCII string to an integer.
 *
 * @param nptr String to convert.
 *
 * @return Converted integer (INT_MIN when input equals "-2147483648").
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
	while (nptr[i])
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}

/**
 * @brief Computes the absolute value of an integer.
 *
 * @param n Number to process.
 *
 * @return Absolute value (INT_MAX when input is INT_MIN).
 */
int	ft_abs(int n)
{
	if (n == INT_MIN)
		return (INT_MAX);
	if (n < 0)
		n *= -1;
	return (n);
}

/**
 * @brief Returns the maximum of two integers.
 *
 * @param x First number.
 * @param y Second number.
 *
 * @return The larger of `x` and `y`.
 */
int	ft_max(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

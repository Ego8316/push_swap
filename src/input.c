/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 05:58:08 by ego               #+#    #+#             */
/*   Updated: 2024/12/17 19:19:19 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Checks if the given character is a digit.
 *
 * @param c Character to test.
 *
 * @return 1 if digit, 0 otherwise.
 */
static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * @brief Validates whether the string represents a 32-bit integer.
 *
 * @param s String to validate.
 *
 * @return 1 if valid, 2 if it represents zero, 0 otherwise.
 */
static int	ft_isint(char *s)
{
	int			i;
	int			j;
	long int	n;

	i = 0;
	j = 0;
	n = 0;
	if ((s[i] == '+' || s[i] == '-') && s[i + 1])
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		if (s[i] == '0')
			j++;
		n = n * 10 + (s[i] - '0');
		if (n > ((long int)INT_MAX + (s[0] == '-')))
			return (0);
		i++;
	}
	if ((j + (s[0] == '+' || s[0] == '-')) == i)
		return (2);
	return (1);
}

/**
 * @brief Checks if the argument list contains duplicates.
 *
 * @param argv Argument vector starting at argv[0].
 *
 * @return 1 when duplicates are found, 0 otherwise.
 */
static int	have_duplicates(char **argv)
{
	int	i;
	int	j;
	int	shift_i;
	int	shift_j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			shift_i = argv[i][0] == '+';
			shift_j = argv[j][0] == '+';
			if (i != j && !ft_strcmp(argv[i] + shift_i, argv[j] + shift_j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * @brief Validates the command-line arguments.
 *
 * Rules:
 * - Every token must be an integer in range.
 * - At most one zero across all inputs.
 * - No duplicate values (ignoring leading '+').
 *
 * @param argc Argument count.
 * @param argv Argument vector.
 *
 * @return 1 if valid, 0 otherwise.
 */
int	check_argument(int argc, char **argv)
{
	int	i;
	int	isint;
	int	zeros;

	i = 1;
	zeros = 0;
	while (i < argc)
	{
		if (!argv[i][0])
			return (0);
		isint = ft_isint(argv[i]);
		if (isint == 0)
			return (0);
		else if (isint == 2)
			zeros++;
		i++;
	}
	if (have_duplicates(argv) || zeros > 1)
		return (0);
	return (1);
}

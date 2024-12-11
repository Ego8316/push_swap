/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 05:58:08 by ego               #+#    #+#             */
/*   Updated: 2024/12/11 01:16:30 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	ft_isdigit
*	Checks if the given character is a digit.
*	Return: 1 if the character is a digit, 0 otherwise.
*/
static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/*	ft_isint
*	Checks if the given string corresponds to an integer.
*	Return: 1 if the string is an int, 2 if it is a zero, 0 otherwise.
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

/*	have_duplicates
*	Checks if there are duplicates inside the input.
*	Return: 1 if there are duplicates, 0 otherwise.
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

/*	check_argument
*	Checks if the given argument is correct.
*	Return: 1 if the argument is correct, 0 otherwise.
*/
int	check_argument(char **argv)
{
	int	i;
	int	isint;
	int	zeros;

	i = 1;
	zeros = 0;
	while (argv[i])
	{
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

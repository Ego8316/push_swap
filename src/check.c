/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 05:58:08 by ego               #+#    #+#             */
/*   Updated: 2024/12/01 07:30:06 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	ft_isdigit
*   Checks if the given character is a digit.
*   Return: 1 if the character is a digit, 0 if not.
*/
static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/*	ft_isnumber
*   Checks if the given string corresponds to a number.
*   Return: 1 if the string corresponds to a number, 0 if not.
*	Returns 2 if the string corresponds to a zero.
*/
int	ft_isnumber(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((s[i] == '+' || s[i] == '-') && s[i + 1])
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		if (s[i] == '0')
			j++;
		i++;
	}
	if ((j + (s[0] == '+' || s[0] == '-')) == i)
		return (2);
	return (1);
}

/*	ft_strcmp
*   Checks if the two given strings are identical.
*   Return: 1 if the strings differ, 0 if not.
*/
static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

/*	have_duplicates
*   Checks if there are duplicates inside the input.
*   Return: 1 if there are duplicates, taking into account
	the case n, +n; 0 if not.
*/
static int	have_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (!ft_strcmp(argv[i] + (argv[i][0] == '+'), argv[j]) && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*	ft_isnumber
*   Checks if the given argument if correct.
*   Return: 1 if the argument is correct, 0 if not.
*/
int	check_argument(char **argv)
{
	int	i;
	int	isnumber;
	int	zeros;

	i = 1;
	zeros = 0;
	while (argv[i])
	{
		isnumber = ft_isnumber(argv[i]);
		if (isnumber == 0)
			return (0);
		else if (isnumber == 2)
			zeros++;
		i++;
	}
	if (have_duplicates(argv) || zeros > 1)
		return (0);
	return (1);
}

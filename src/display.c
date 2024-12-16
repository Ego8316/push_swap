/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:12:52 by ego               #+#    #+#             */
/*   Updated: 2024/12/15 18:21:37 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	return ;
}

void	ft_putstr_error(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, str, len);
	return ;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		n %= 10;
	}
	ft_putchar('0' + n);
	return ;
}

void	stack_print(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_putnbr(stack_a->value);
			stack_a = stack_a->next;
		}
		if (stack_b)
		{
			ft_putchar('\t');
			ft_putnbr(stack_b->value);
			stack_b = stack_b->next;
		}
		ft_putchar('\n');
	}
	ft_putstr("_\t_\na\tb\n");
	return ;
}

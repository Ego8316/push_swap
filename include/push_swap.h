/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:58:57 by ego               #+#    #+#             */
/*   Updated: 2024/12/01 07:04:10 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

// Stack utilities
t_stack	*stack_new(int value);

// Operations

// Display utilities
void	ft_putstr(char *str);

// Check utilities
int		ft_isnumber(char *s);
int		check_argument(char **argv);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:46:57 by ego               #+#    #+#             */
/*   Updated: 2024/12/19 03:07:08 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif
# define FD_MAX 1024
# define ERROR "\033[31mError\033[0m\n"
# define OK "\033[32mOK\033[0m\n"
# define KO "\033[31mOK\033[0m\n"

typedef struct s_stack
{
	int				value;
	int				rank;
	struct s_stack	*next;
}	t_stack;

// Stack utilities
t_stack	*stack_new(int value);
t_stack	*stack_fill(char **argv);
void	stack_free(t_stack **stack);
int		stack_issorted(t_stack *stack);
int		stack_size(t_stack *stack);

// Operations
void	sa(t_stack **stack_a, int display);
void	sb(t_stack **stack_b, int display);
void	ss(t_stack **stack_a, t_stack **stack_b, int display);
void	pa(t_stack **stack_a, t_stack **stack_b, int display);
void	pb(t_stack **stack_a, t_stack **stack_b, int display);
void	ra(t_stack **stack_a, int display);
void	rb(t_stack **stack_b, int display);
void	rr(t_stack **stack_a, t_stack **stack_b, int display);
void	rra(t_stack **stack_a, int display);
void	rrb(t_stack **stack_b, int display);
void	rrr(t_stack **stack_a, t_stack **stack_b, int display);

// get_next_line
char	*get_next_line(int fd);
int		ft_char_in_str(char c, char *s);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_calloc(size_t nmemb, size_t size);

// Display utilities
void	ft_putstr(char *str);
void	ft_putstr_error(char *str);

// Argument checking
int		check_argument(int argc, char **argv);

// Utilities
int		ft_free(char **s);
void	exit_error(t_stack **stack_a, t_stack **stack_b);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *nptr);
int		ft_abs(int n);
int		ft_max(int x, int y);

#endif
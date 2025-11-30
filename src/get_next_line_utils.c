/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:50:37 by ego               #+#    #+#             */
/*   Updated: 2025/11/30 20:00:05 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/** 
 * @brief Sets a block of memory to a specified value.
 * 
 * @param b The memory block to set.
 * @param c The value to set the memory to.
 * @param len The number of bytes to set.
 * 
 * @return A pointer to the memory block.
 */
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

/** 
 * @brief Moves a block of memory to another location safely, handling overlap.
 * 
 * @param dst The destination memory block.
 * @param src The source memory block.
 * @param len The number of bytes to move.
 * 
 * @return A pointer to the destination memory block, or NULL if both
 * dst and src are NULL and len is non-zero.
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s = (const unsigned char *)src;

	if (!dst && !src && len > 0)
		return (NULL);
	d = (unsigned char *)dst;
	if ((s < d) && (d < s + len))
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (len-- > 0)
			*d++ = *s++;
	}
	return (dst);
}

/**
 * @brief Returns the length of a string and handles NULL input safely.
 *
 * @param str The string to measure (can be NULL).
 *
 * @return The length of the string, 0 if the string is NULL.
 */
size_t	ft_strlen_null(const char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

/**
 * @brief Goes through the string s to search for
 * the first occurence of the character c. If found,
 * returns the position, -1 otherwise.
 * 
 * @param c Character to find.
 * @param s String to be searched.
 * 
 * @return Position of the character, -1 otherwise.
 */
int	ft_char_in_str(char c, const char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

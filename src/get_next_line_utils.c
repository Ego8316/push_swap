/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:50:37 by ego               #+#    #+#             */
/*   Updated: 2024/12/17 19:01:20 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_char_in_str(char c, char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	if (!s)
		return (ft_strdup(""));
	i = 0;
	while (s[i])
		i++;
	dup = (char *)ft_calloc(i + 1, sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*ndup;
	size_t	i;

	if (!s || !n)
		return (ft_strdup(""));
	ndup = (char *)ft_calloc(n + 1, sizeof(char));
	if (!ndup)
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		ndup[i] = s[i];
		i++;
	}
	return (ndup);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!s1)
		return (ft_strdup(s2));
	j = 0;
	while (s1[j])
		j++;
	i = 0;
	while (s2[i])
		i++;
	join = (char *)ft_calloc((i + j + 1), sizeof(char));
	if (!join)
		return (NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	j = -1;
	while (s2[++j])
		join[i + j] = s2[j];
	return (join);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	i;

	array = (void *)malloc(nmemb * size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((unsigned char *)array)[i] = '\0';
		i++;
	}
	return (array);
}

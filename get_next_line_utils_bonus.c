/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:26:44 by dlopes-d          #+#    #+#             */
/*   Updated: 2023/05/08 19:32:29 by dlopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		++i;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	ch;
	char	*str;

	i = 0;
	ch = (char) c;
	str = (char *) s;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == ch)
		{
			return (str + i);
		}
		++i;
	}
	if (ch == str[i])
	{
		return (str + i);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*joined;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	joined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	while (s1[++i])
		joined[i] = s1[i];
	while (s2[++j])
	{
		joined[i + j] = s2[j];
	}
	joined[i + j] = '\0';
	free(s1);
	return (joined);
}

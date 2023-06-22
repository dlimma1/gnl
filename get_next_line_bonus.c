/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:59:43 by dlopes-d          #+#    #+#             */
/*   Updated: 2023/05/09 17:12:37 by dlopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Write a function that returns a line read from a file descriptor.
//
//	Return Read line: correct behavior
//	Return NULL: there is nothing else to read, or an error occurred

#include "get_next_line_bonus.h"

char	*ft_update_buffer(char *buffer)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		++len;
	if (!buffer[len])
	{
		free(buffer);
		return (NULL);
	}
	str = (char *) malloc(sizeof(char) * (ft_strlen(buffer) - len + 1));
	if (!str)
		return (NULL);
	++len;
	while (buffer[len])
		str[i++] = buffer[len++];
	str[i] = '\0';
	free(buffer);
	return (str);
}

char	*ft_get_line(char *buffer)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = 0;
	if (!buffer[len])
		return (NULL);
	while (buffer[len] && buffer[len] != '\n')
		++len;
	str = (char *) malloc(sizeof(char) * (len + 2));
	if (!str)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		++i;
	}
	if (buffer[i] == '\n')
	{
		str[i] = buffer[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_read_str_buffer(int fd, char *buffer)
{
	int		read_bytes;
	char	*str_buffer;

	read_bytes = 1;
	str_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str_buffer)
		return (NULL);
	while (!(ft_strchr(buffer, '\n')) && (read_bytes != 0))
	{
		read_bytes = read(fd, str_buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{	
			free(buffer);
			free(str_buffer);
			return (NULL);
		}
		if (!str_buffer)
			return (NULL);
		str_buffer[read_bytes] = '\0';
		buffer = ft_strjoin(buffer, str_buffer);
	}
	free(str_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[FILES];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FILES)
		return (0);
	buffer[fd] = ft_read_str_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_update_buffer(buffer[fd]);
	return (line);
}

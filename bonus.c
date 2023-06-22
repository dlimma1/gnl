/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bon.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:16:16 by dlopes-d          #+#    #+#             */
/*   Updated: 2023/05/08 19:20:29 by dlopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;
	char	titles[3][20] = {"poem.txt", "math.txt", "article.txt"};

	for (int i = 0; i < 3; i++)
	{
		printf("\n\nREADING file %i...\n\n", i + 1);
		fd = open(titles[i], O_RDONLY);
		if (fd == -1)
			return(1);
		line = get_next_line(fd);
		while (line)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return(0);
}

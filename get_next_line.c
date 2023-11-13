/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:59:46 by yadereve          #+#    #+#             */
/*   Updated: 2023/11/13 16:21:22 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{

}

int	main()
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("file opening filed");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("line: %s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}

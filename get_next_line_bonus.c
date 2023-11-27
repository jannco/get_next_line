/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:24:48 by yadereve          #+#    #+#             */
/*   Updated: 2023/11/27 19:24:59 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FILE_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			flag;

	i = 0;
	flag = 1;
	if (fd >= FILE_MAX || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		if (fd > 0 && fd < FILE_MAX && read(fd, NULL, 0) >= 0)
			while (BUFFER_SIZE > i)
				buffer[fd][i++] = '\0';
		return (NULL);
	}
	line = NULL;
	while (flag && (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE)))
	{
		line = ft_strjoin(line, buffer[fd]);
		ft_freebuffer(&flag, buffer[fd]);
		if (!line)
			return (NULL);
	}
	return (line);
}
/*
int	main(int	argc, char	**argv)
{
	int		fd[argc - 1];
	char	*line;
	int		i = 0;
	int		flag = 0;

	line = NULL;
	if (argc <= 1)
	{
		write(1, "Write some arguments\n", 21);
		return (1);
	}
	while (i < (argc - 1))
	{
		fd[i] = open(argv[i + 1], O_RDONLY);
		i++;
	}
	i = 0;
	while (flag == (argc - 1))
	{
		line = get_next_line(fd[i++]);
		if (!line)
			printf("Line: %s", line);
		if (i == (argc - 1))
			i = 0;
		if (i < argc && !line)
			flag++;
	}
	while (!i)
		close(fd[i--]);
	return (0);
} */

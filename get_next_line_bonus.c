/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:24:48 by yadereve          #+#    #+#             */
/*   Updated: 2023/11/17 10:52:08 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			flag;

	i = 0;
	flag = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		while (fd >= 0 && BUFFER_SIZE > i)
			buffer[i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (flag && (buffer[0] || (read(fd, buffer, BUFFER_SIZE) > 0)))
	{
		line = ft_strjoin(line, buffer);
		ft_freebuffer(&flag, buffer);
	}
	return (line);
}

int main(void)
{
	int		fd1, fd2, fd3;
	char	*line;

	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	fd3 = open("file3.txt", O_RDONLY);

	if (fd1 < 0 || fd2 < 0 || fd3 < 0) {
		perror("file opening failed");
		return 1;
	}
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("File 1: %s\n", line);
		free(line);
	}
	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("File 2: %s\n", line);
		free(line);
	}
	while ((line = get_next_line(fd3)) != NULL)
	{
		printf("File 3: %s\n", line);
		free(line);
	}

	// Закриваємо файли
	close(fd1);
	close(fd2);
	close(fd3);

	return 0;
}

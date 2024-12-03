/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:11:26 by zirtaee           #+#    #+#             */
/*   Updated: 2024/12/02 20:36:52 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	t_data		data;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data.line = NULL;
	while (1)
	{
		if (!buffer[0])
		{
			data.bytes_count = read(fd, buffer, BUFFER_SIZE);
			if (data.bytes_count == 0)
				return (result(data, buffer, ft_clean_buffer, 0));
			if (data.bytes_count < 0)
				return (result(data, buffer, ft_clean_buffer, 1));
		}
		data.line = ft_strjoin(data.line, buffer, data);
		if (ft_strchr(buffer, '\n', data))
			return (result(data, buffer, ft_clean_buffer, 0));
		ft_clean_buffer (buffer, data);
	}
	return (data.line);
}

/* int	main(void)
{
	int fd = open("file.txt", O_RDONLY);
	char *line;

	if(fd < 0)
	{
		printf("Error opening the file");
		return (1);
	}
	line = get_next_line(fd);
		printf("->%s", line);
	while (line)
	{
		free (line);
		line = get_next_line(fd);
		printf("->%s", line);
	}
	close (fd);
	return (0);
} */
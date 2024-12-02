/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zirtaee <zirtaee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:11:26 by zirtaee           #+#    #+#             */
/*   Updated: 2024/12/02 17:36:10 by zirtaee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char     buffer[BUFFER_SIZE + 1];
    unsigned int    bytes_count;
    char            *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = NULL;
    while (1)
    {
        if (!buffer[0])
        {
            bytes_count = read(fd, buffer, BUFFER_SIZE);
            if (bytes_count == 0)
                return(result(line, buffer, ft_clean_buffer, 0));
            if (bytes_count < 0)
                return(result(line, buffer, ft_clean_buffer, 1));
        }
        line = ft_strjoin(line, buffer);
        if (ft_strchr(buffer, '\n'))
            return(result(line, buffer, ft_clean_buffer, 0));
        ft_clean_buffer(buffer);
    }
    return (line);
}

int	main(void)
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
}
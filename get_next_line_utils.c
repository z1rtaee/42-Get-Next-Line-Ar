/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zirtaee <zirtaee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:10:59 by zirtaee           #+#    #+#             */
/*   Updated: 2024/12/02 18:31:34 by zirtaee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char     *ft_strchr(const char *s, int c, t_data data)
{
	data.i = 0;
	while (s[data.i])
	{
		if (s[data.i] == (char)c)
			return ((char *)&s[data.i]);
		data.i++;
	}
	if (s[data.i] == (char)c)
		return ((char *)&s[data.i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

int	ft_clean_buffer(char buffer[BUFFER_SIZE + 1])
{
	int i;
	int	j;

	i = 0;
	j = 0;
	int check = 0;

	while(i < BUFFER_SIZE)
	{
		if(check)
		{
			buffer[j] = buffer[i];
			j++;
		}
		if(buffer[i] == '\n')
			check = 1;
		buffer[i] = '\0';
		i++;
	}
	return(1);
}

char *ft_strjoin(char *s1, char const *s2, t_data data)
{
	data.len = ft_strlen(s1) + ft_strlen(s2);
	data.res = (char *)malloc(sizeof(char) * data.len + 1);
	if (!data.res)
		return (NULL);
	data.i = 0;
	data.j = 0;
	while (s1 && s1[data.i])
		data.res[data.j++] = s1[data.i++];
	data.i = 0;
	while (s2 && s2[data.i])
	{
    	data.res[data.j++] = s2[data.i++];
        if (data.res[data.j - 1] == '\n')
			break;
    }
	data.res[data.j] = '\0';
	if (s1)
		free(s1);
	return (data.res);
}

char *result(char *line, char *buffer, int(*f)(char *), int i)
{
	f(buffer);
	if (i == 1)
	{
		if (line)
			free(line);
		return (NULL);
	}
	return (line);
}
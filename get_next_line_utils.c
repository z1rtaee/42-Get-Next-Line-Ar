/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zirtaee <zirtaee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:10:59 by zirtaee           #+#    #+#             */
/*   Updated: 2024/12/02 17:38:42 by zirtaee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char     *ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
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

char *ft_strjoin(char *s1, char const *s2)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
	{
    	res[j++] = s2[i++];
        if (res[j - 1] == '\n')
			break;
    }
	res[j] = '\0';
	if (s1)
		free(s1);
	return (res);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zirtaee <zirtaee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:11:59 by zirtaee           #+#    #+#             */
/*   Updated: 2024/12/02 18:25:44 by zirtaee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct s_data
{
    char			*res;
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
    unsigned int    bytes_count;
    char            *line;
}					t_data;

char        *get_next_line(int fd);
size_t      ft_strlen(const char *s);
char        *ft_strchr(const char *s, int c, t_data data);
char        *ft_strjoin(char *s1, char const *s2, t_data data);
int	        ft_clean_buffer(char buffer[BUFFER_SIZE + 1]);
char        *result(char *line, char *buffer,int(*f)(char *), int i);

#endif
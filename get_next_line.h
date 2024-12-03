/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:11:59 by zirtaee           #+#    #+#             */
/*   Updated: 2024/12/02 20:49:43 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int				bytes_count;
	int				check;
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	char			*res;
	char			*line;
}					t_data;

char				*get_next_line(int fd);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c, t_data data);
char				*ft_strjoin(char *s1, char const *s2, t_data data);
int					ft_clean_buffer(char buffer[BUFFER_SIZE + 1], t_data data);
char				*result(t_data data, char *buffer, int (*f)(char *, t_data),
						int i);

#endif
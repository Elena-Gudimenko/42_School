/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:02:17 by elvictor          #+#    #+#             */
/*   Updated: 2024/12/04 18:35:32 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_line_buffer(int fd, char *rest_buff, char *read_buffer);
static char	*free_buffer(char **read_buffer);
static char	*ft_strchr(const char *s, int c);
static char	*set_line(char *line_buffer);

char	*get_next_line(int fd)
{
	static char	*rest_buff = NULL;
	char		*line;
	char		*read_buffer;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	read_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buffer)
		return (NULL);
	line = fill_line_buffer(fd, rest_buff, read_buffer);
	free_buffer(&read_buffer);
	if (!line)
		return (free_buffer(&rest_buff));
	rest_buff = set_line(line);
	return (line);
}

static char	*set_line(char *line_buffer)
{
	char	*rest;
	int		line_len;
	int		rest_len;

	line_len = 0;
	while (line_buffer[line_len] != '\n' && line_buffer[line_len] != '\0')
		line_len++;
	if (line_buffer[line_len] == '\n')
		line_len++;
	rest_len = ft_strlen(line_buffer) - line_len;
	if (rest_len > 0)
	{
		rest = ft_substr(line_buffer, line_len, rest_len);
		line_buffer[line_len] = '\0';
	}
	else
		rest = NULL;
	return (rest);
}

static char	*fill_line_buffer(int fd, char *rest_buff, char *read_buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		read_buffer[bytes_read] = '\0';
		if (!rest_buff)
			rest_buff = ft_calloc(1, sizeof(char));
		temp = rest_buff;
		rest_buff = ft_strjoin(temp, read_buffer);
		free_buffer(&temp);
		if (ft_strchr(read_buffer, '\n'))
			break ;
	}
	return (rest_buff);
}

static char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

static char	*free_buffer(char **read_buffer)
{
	if (read_buffer && *read_buffer)
	{
		free(*read_buffer);
		*read_buffer = NULL;
	}
	return (NULL);
}

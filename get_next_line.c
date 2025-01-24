/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osouadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:16:47 by osouadi           #+#    #+#             */
/*   Updated: 2025/01/05 17:16:49 by osouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_rest(char *content, char **line)
{
	char	*str;
	int		i;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (!content[i])
	{
		free(content);
		return (NULL);
	}
	i++;
	str = ft_strdup(&content[i]);
	if (!str)
	{
		free(content);
		free(*line);
		*line = NULL;
		return (NULL);
	}
	return (free(content), str);
}

static char	*ft_get_line(char *content)
{
	char	*str;
	int		i;

	i = 0;
	if (!content || !content[0])
		return (NULL);
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\n')
		str = (char *)malloc(i + 2);
	else
		str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (content[i] != '\n' && content[i])
	{
		str[i] = content[i];
		i++;
	}
	if (content[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

static char	*ft_stock(char *content, char *buffer)
{
	char	*str;

	str = ft_strjoin(content, buffer);
	if (!str)
	{
		free(content);
		free(buffer);
		return (NULL);
	}
	free(content);
	return (str);
}

static char	*ft_read(int fd, char *content)
{
	char	*buffer;
	ssize_t	byts_read;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (free(content), NULL);
	byts_read = 1;
	while (byts_read > 0)
	{
		byts_read = read(fd, buffer, BUFFER_SIZE);
		if (byts_read == -1)
			return (free(content), free(buffer), NULL);
		if (!content)
			content = ft_strdup("");
		if (!content)
			return (free(buffer), NULL);
		buffer[byts_read] = '\0';
		content = ft_stock(content, buffer);
		if (!content)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), content);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (content)
		{
			free(content);
			content = NULL;
		}
		return (NULL);
	}
	content = ft_read(fd, content);
	if (!content)
		return (NULL);
	line = ft_get_line(content);
	if (!line)
		return (free(content), content = NULL, NULL);
	content = ft_rest(content, &line);
	return (line);
}

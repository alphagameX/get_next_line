/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atinseau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:35:31 by atinseau          #+#    #+#             */
/*   Updated: 2020/11/29 14:52:53 by atinseau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		has_return(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*substr(char *str, int start, int len, int is_free)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (str == NULL)
	{
		*new = '\0';
		return (new);
	}
	while (str[start] && i < len)
	{
		new[i] = str[start];
		i++;
		start++;
	}
	new[i] = '\0';
	if (is_free == 1)
		free(str);
	return (new);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	static char		*str[MAX_FD];
	char			*temp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 ||
			!(temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (has_return(str[fd]) == 0 && (ret = read(fd, temp, BUFFER_SIZE)))
	{
		if (ret == -1)
		{
			free(temp);
			return (-1);
		}
		temp[ret] = '\0';
		str[fd] = ft_strjoin(str[fd], temp);
	}
	free(temp);
	if (!has_return(str[fd]))
		return (last_line(line, str[fd]));
	*line = substr(str[fd], 0, p(str[fd]), 0);
	str[fd] = substr(str[fd], p(str[fd]) + 1, len(str[fd]) - p(str[fd]), 1);
	return (1);
}

int		last_line(char **line, char *str)
{
	*line = substr(str, 0, len(str), 0);
	if (str)
		*str = '\0';
	return (0);
}

int		p(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

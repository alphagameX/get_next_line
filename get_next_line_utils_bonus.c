/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atinseau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:54:56 by atinseau          #+#    #+#             */
/*   Updated: 2020/11/29 14:57:47 by atinseau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		e;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) *
			(len(s1) + len(s2)) + 1)))
		return (NULL);
	e = 0;
	i = 0;
	while (s1 && s1[i] != '\0')
		new[e++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		new[e++] = s2[i++];
	new[e] = '\0';
	free(s1);
	return (new);
}

int		len(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

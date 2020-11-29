/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atinseau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 12:11:46 by atinseau          #+#    #+#             */
/*   Updated: 2020/11/29 14:50:19 by atinseau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_strlen(char *str);
int		pos_n(char *str);
int		last_line(char **line, char *str);

#endif

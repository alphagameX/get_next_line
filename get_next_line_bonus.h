/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atinseau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:51:23 by atinseau          #+#    #+#             */
/*   Updated: 2020/11/29 14:54:07 by atinseau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define MAX_FD 65540
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		len(char *str);
int		p(char *str);
int		last_line(char **line, char *str);

#endif

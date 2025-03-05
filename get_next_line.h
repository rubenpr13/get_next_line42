/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinazo- <rpinazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:33:02 by rpinazo-          #+#    #+#             */
/*   Updated: 2025/03/05 14:14:54 by rpinazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#ifndef     BUFFER_SIZE
# define    BUFFER_SIZE 24
#endif

char    *get_next_line(int fd);
char    *line_remaining(char *stat_buff);
char    *ft_line(char *stat_buff);

int     ft_strlen(char *str);
char    *ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t size, size_t type);
int     ft_strchr(char *str, char chr);

#endif
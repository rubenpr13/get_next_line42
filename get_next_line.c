/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinazo- <rpinazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:32:11 by rpinazo-          #+#    #+#             */
/*   Updated: 2025/03/06 15:42:21 by rpinazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char    *line_remaining(char *stat_buff);
char    *ft_line(char *stat_buff);
char    *read_buff(int fd, char *stat_buff);


char    *get_next_line(int fd)
{
    static char *stat_buff;
    char        *line;

    stat_buff = read_buff(fd, stat_buff);
    if (!stat_buff)
        return (NULL);
        
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(stat_buff);
        stat_buff = NULL;
        return (NULL);
    }
    if (ft_strlen(stat_buff) < 1)
    {
        free(stat_buff);
        stat_buff = NULL;
        return(NULL);
    }
    line = ft_line(stat_buff);
    stat_buff = line_remaining(stat_buff);
    return (line);
}

char *line_remaining(char *stat_buff)
{
    char    *line;
    int     i;
    int     j;

    i = 0;
    while (stat_buff[i] && stat_buff[i] != '\n')
        i++;
    if (!stat_buff[i])
    {
        free(stat_buff);
        stat_buff = NULL;
        return (NULL);
    }
    line = ft_calloc((ft_strlen(stat_buff) - i + 1), sizeof(char));
    i++;
    j = 0;
    while(stat_buff[i])
        line[j++] = stat_buff[i++];
    free(stat_buff);
    return(line);
}

char    *ft_line(char *stat_buff)
{
    char    *line;
    int     i;

    i = 0;
    if(!stat_buff[i])
        return(NULL);
    while (stat_buff[i] && stat_buff[i] != '\n')
        i++;
    line = ft_calloc(i + 2, sizeof(char));
    i = 0;
    while (stat_buff[i] && stat_buff[i] != '\n')
    {
        line[i] = stat_buff[i];
        i++;
    }
    if (stat_buff[i] && stat_buff[i] == '\n')
    {
        line[i] = stat_buff[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

char    *read_buff(int fd, char *stat_buff)
{
    char    *buffer;
    int     result;

    if (!stat_buff)
        stat_buff = ft_calloc(1, sizeof(char));
    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buffer)
    {
        free(stat_buff);
        stat_buff = NULL;
        return (NULL);
    }
    
    result = 1;
    while (result > 0)
    {
        result = read(fd, buffer, BUFFER_SIZE);
        if (result < 0)
        {
            free(buffer);
            buffer = NULL;
            free(stat_buff);
            stat_buff = NULL;
            return (NULL);
        }
        buffer[result] = '\0';
        stat_buff = ft_strjoin(stat_buff, buffer);
        if (ft_strchr(buffer, '\n') == 1)
            break;
    }
    free(buffer);
    return (stat_buff);
}

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        while ((line = get_next_line(fd)))
        {
            printf("%s", line);
            free(line);
        }
        free(line);
        close(fd);
    }
    return (0);
}
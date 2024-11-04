/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneiva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:18:50 by jneiva-s          #+#    #+#             */
/*   Updated: 2024/10/05 14:18:53 by jneiva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char *line;
    int bytesToRead;

if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
line = NULL;
// se o buffer já existir
    if (buffer[0] != '\0')
        line = ft_strjoin(line, buffer, ft_strlen(line), ft_strlen(buffer));
        
// se for a primeira leitura ou ultima
    if (ft_breakline_exists(line)==-1)
    {
        bytesToRead = read(fd,buffer,BUFFER_SIZE);
        buffer[bytesToRead] = '\0';
        if(bytesToRead == 0)
            return (line);
        if(bytesToRead < 0)
            return (NULL);
        line = ft_strjoin(line, buffer, ft_strlen(line), ft_strlen(buffer));
    }

    return(ft_cut_line(line, buffer));
}

// int main(int argc, char **argv)
// {
//     int fd;
//     char* fileName = "text.txt";
// 	char *result;
//     if (argc > 1)
//         fileName = argv[1];
//     fd = open(fileName, O_RDWR);
//     result = get_next_line(fd);
// 	printf("%s", result);
// 	result = get_next_line(fd);
// 	printf("%s", result);
// 	// if(!result)
// 	// 	free(result);
// 	// else
// 	// 	printf("%s", result);
		
// }


int main(int argc, char **argv)
{
	int fd;
    char *fileName = "text.txt";
    char *result;

    if (argc > 1)
        fileName = argv[1];
    fd = open(fileName, O_RDWR);
    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }

    while ((result = get_next_line(fd)) != NULL)
    {
        printf("%s", result);
        free(result);
    }
    close(fd);
    return 0;
    // int fd;
    // char* fileName = "text.txt";
	// char *result;
    // if (argc > 1)
    //     fileName = argv[1];
    // fd = open(fileName, O_RDWR);
    // result = get_next_line(fd);
	// printf("%s", result);
	// result = get_next_line(fd);
	// printf("%s", result);
	// // if(!result)
	// // 	free(result);
	// // else
	// // 	printf("%s", result);
}
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
char	*ft_strjoin(const char *s1, const char *s2);
int	ft_strlcpy(char *dest, const char *src, size_t size);
int	ft_strlcat(char *dest, const char *src, unsigned int size);
int	ft_strlen2(char *str, int len);
int	ft_strlen(const char *str);

char *get_next_line(int fd)
{
    size_t  bits;
	bits = 100;
    int bytesRead;
    int i;
    char *line;

    // line = NULL;
    static char	buffer[1024];

    bytesRead = read(fd, buffer, bits);
	printf("%d",bytesRead);
	// printf("\n %d",ft_strlen(line));

	int new_line = ft_strlen2(buffer, 50);
	printf("\n %d",new_line);

line = ft_strjoin(line, buffer);
	// line = (char *)malloc(new_line+1);

	// for (int j = 0; j < new_line; j++)
	// {
	// 	line[j] = buffer[j];
	// 	printf("%c",line[i+j]);
	// }
	// line[new_line]='\0';
	// printf("%s", line);
    // line = ft_strjoin(line, buffer);
    // ft_print_line();
    // printf("%s",line);
	return (line);
    // return(buffer);
}
int	ft_strlen2(char *str, int len)
{
	int	i;

	i = 0;
	if(!str)
		return 0;
	while (str[i] != '\0' && i<len)
	{
		// write(1,&str[i],1);
		if(str[i]=='\n')
			return i;
		i++;
	}
	return (i);
}

// int	ft_strlen(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0' && str[i]!='\n')
// 	{
// 		write(1,&str[i], 1);
// 		printf("%d", i);
// 		i++;
// 	}
// 	return (i);
// }
int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < size)
		i++;
	while (src[j] != '\0' && i + j + 1 < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < size)
		dest[i + j] = '\0';
	while (src[j] != '\0')
		j++;
	if (i < size)
		return (i + j);
	else
		return (size + j);
}
int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*final;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen2(s1,100);
	s2len = ft_strlen2(s2,100);
	if (!s1 || !s2)
		return (NULL);
	final = (char *)malloc(s1len + s2len + 1);
	if (!final)
		return (NULL);
	ft_strlcpy(final, s1, s1len + 1);
	ft_strlcat(final, s2, s1len + s2len + 1);
	return (final);
}
int main(int argc, char **argv)
{
    int fd;
    char* fileName = "text.txt";
	char *result;
    if (argc > 1)
        fileName = argv[1];
    fd = open(fileName, O_RDWR);
    result = get_next_line(fd);
	printf("%s", result);
	result = get_next_line(fd);
	printf("%s", result);
	// if(!result)
	// 	free(result);
	// else
	// 	printf("%s", result);
		
}

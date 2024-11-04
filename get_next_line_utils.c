/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneiva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:19:17 by jneiva-s          #+#    #+#             */
/*   Updated: 2024/10/05 14:19:19 by jneiva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_breakline_exists(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, size_t len_s1, size_t len_s2)
{
	int		i;
	char	*str;

	str = malloc(((len_s1 + len_s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 != NULL && *s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	free(s1 - len_s1);
	return (str);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	int		i;
// 	char	*str;

// 	str = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i] != '\0')
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	while (*s2)
// 	{
// 		str[i] = s2;
// 		i++;
// 		s2++;
// 	}
// 	str[i] = '\0';
// 	free(s1);
// 	return (str);
// }
char	*ft_cut_line(char *line, char *buffer)
{
	int		i;
	int		breakline;
	char	*final_line;

	i = 0;
	breakline = ft_breakline_exists(buffer) + 1;
	final_line = malloc((ft_breakline_exists(line) + 2) * sizeof(char));
	if (!final_line)
		return (NULL);
	while(line[i] !='\0' && line[i]!='\n')
	{
		final_line[i] = line[i];
		i++;
	}
	final_line[i] = '\n';
	final_line[i+1]= '\0';
	free(line);
	i = 0;
	while (buffer[i])
		buffer[i++] = buffer[breakline++];
	return (final_line);
}
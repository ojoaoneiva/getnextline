/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneiva-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:18:37 by jneiva-s          #+#    #+#             */
/*   Updated: 2024/10/05 14:18:39 by jneiva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
#include <fcntl.h>

char *buffer;

char *get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
int	ft_strlcpy(char *dest, const char *src, size_t size);
int	ft_strlcat(char *dest, const char *src, unsigned int size);
int	ft_strlen(const char *str);
// int	ft_strlen(const char *str);

#endif

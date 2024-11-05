#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define OPEN_MAX 1024

char *get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, size_t len_s1, size_t len_s2);
char	*ft_cut_line(char *line, char *buffer);
int	ft_strlcpy(char *dest, const char *src, size_t size);
int	ft_strlcat(char *dest, const char *src, unsigned int size);
int	ft_strlen(char *str);
int	ft_breakline_exists(char *buffer);
#endif
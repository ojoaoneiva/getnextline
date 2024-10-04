#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>

char *buffer;

char *get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
int	ft_strlen(const char *str);

#endif
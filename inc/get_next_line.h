#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*read_and_save(int fd, char *stash);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);

#endif
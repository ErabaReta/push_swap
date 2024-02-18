#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>

char	**ft_split(char const *s, char c);
size_t	count_words(char const *s, char c);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *s1);
int	ft_strlen(const char *s);

#endif
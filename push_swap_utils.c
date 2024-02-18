#include "push_swap.h"

static size_t	indexer(char const *s, char c, size_t i, size_t *end_index)
{
	while (s[i] != c && s[i] != '\0')
		i++;
	*end_index = i;
	return (i);
}

size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 1;
	count = 0;
	if (s == NULL || s[0] == '\0')
		return (0);
	if (s[0] != c)
		count++;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static void	*extracter(char *ptr, size_t *end_index,
						size_t *start_index, const char *s)
{
	ptr = (char *)malloc(sizeof(char) * (*end_index - *start_index + 1));
	if (ptr == NULL)
		return (NULL);
	ft_memmove(ptr, s + *start_index, *end_index - *start_index);
	ptr[*end_index - *start_index] = '\0';
	*start_index = *end_index;
	return (ptr);
}

static void	*free_all(char **ptr, int i)
{
	while (i >= 0)
	{
		free(ptr[i]);
		i--;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	start_index;
	size_t	end_index;

	i = count_words(s, c);
	ptr = (char **)malloc((i + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	start_index = 0;
	while (1)
	{
		while (s != NULL && s[start_index] == c && c != '\0')
			start_index++;
		if (s == NULL || start_index == indexer(s, c, start_index, &end_index))
		{
			ptr[i] = NULL;
			break ;
		}
		ptr[i] = extracter(ptr[i], &end_index, &start_index, s);
		if (ptr[i++] == NULL)
			return (free_all(ptr, --i));
	}
	return (ptr);
}


void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (d > s)
	{
		while (len--)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	j = -1;
	while (s2[++j] != '\0')
		ptr[i + j] = s2[j];
	ptr[i + j] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
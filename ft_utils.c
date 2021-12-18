#include "ft_connect4.h"

/*int ft_isspace(char map[10][9], int winner)
{
	(void)winner;
	for (int j = 1; j < 7; j++)
	{
		if (map[1][j] == ' ')
			return (NOTFULL);
	}
	return (FULL);
}
*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && i + 1 < n)
		i++;
	if ((unsigned char)s1[i] == (unsigned char)s2[i])
		return (0);
	else if ((unsigned char)s1[i] > (unsigned char)s2[i])
		return (1);
	else
		return (-1);
}

char	*ft_strnstr(char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nlen;

	i = 0;
	nlen = ft_strlen(needle);
	if (nlen == 0)
		return ((char *)haystack);
	else if (len == 0)
		return (NULL);
	while (haystack[i] != '\0' && i + nlen <= len)
	{
		if (ft_strncmp(&haystack[i], needle, nlen) == 0)
		{
//			for (int j = 0; j < 4; j++)
//				haystack[i + j] -= 32;
			return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}



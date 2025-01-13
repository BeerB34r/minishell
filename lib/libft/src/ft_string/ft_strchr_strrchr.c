#include <ft.h>

char	*ft_strchr(const char *s, int c)
{
	char	*result;

	result = ft_strchrnul(s, c);
	if (*result == '\0' && (char)c != '\0')
		return (NULL);
	return (result);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = ft_strrchrnul(s, c);
	if (*result == '\0' && (char)c != '\0')
		return (NULL);
	return (result);
}

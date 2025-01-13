#include <ft.h>

char	*ft_basename(char *s)
{
	size_t	start;
	size_t	end;

	if (s == NULL || ft_strlen(s) == 0)
		return (ft_strdup("."));
	if (ft_strcmp(s, "/") == 0)
		return (ft_strdup("/"));
	end = ft_strlen(s);
	while (end > 0 && s[end - 1] == '/')
		end--;
	if (end == 0)
		return (ft_strdup("/"));
	start = end - 1;
	while (start > 0 && s[start - 1] != '/')
		start--;
	return (ft_substr(s, start, end - start));
}

#include <ft.h>

#include <stdbool.h>

static int	get_diff(char c1, char c2, bool ignorecase)
{
	int	v1;
	int	v2;

	if (ignorecase)
	{
		v1 = (unsigned char)ft_toupper(c1);
		v2 = (unsigned char)ft_toupper(c2);
	}
	else
	{
		v1 = (unsigned char)c1;
		v2 = (unsigned char)c2;
	}
	return (v1 - v2);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (!get_diff(s1[i], s2[i], false))
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (get_diff(s1[i], s2[i], false));
}

int	ft_strcasecmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (!get_diff(s1[i], s2[i], true))
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (get_diff(s1[i], s2[i], true));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && !get_diff(s1[i], s2[i], false))
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	if (i >= n)
		return (0);
	return (get_diff(s1[i], s2[i], false));
}

int	ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && !get_diff(s1[i], s2[i], true))
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	if (i >= n)
		return (0);
	return (get_diff(s1[i], s2[i], true));
}

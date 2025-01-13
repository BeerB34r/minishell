#include <ft.h>

void	*ft_memmem(const void *haystack, size_t haystacklen,
			const void *needle, size_t needlelen)
{
	size_t		i;
	size_t		j;
	const char	*chaystack;
	const char	*cneedle;

	chaystack = (const char *)haystack;
	cneedle = (const char *)needle;
	if (needlelen == 0)
		return ((void *)haystack);
	i = 0;
	while (i + needlelen <= haystacklen)
	{
		j = 0;
		while (j < needlelen && chaystack[i + j] == cneedle[j])
			j++;
		if (j == needlelen)
			return ((void *)(&chaystack[i]));
		i++;
	}
	return (NULL);
}

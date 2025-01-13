#include <ft.h>

#define MEMFROB_VALUE 42

void	*ft_memfrob(void *s, size_t n)
{
	size_t	i;
	char	*cs;

	cs = (char *)s;
	i = 0;
	while (i < n)
	{
		cs[i] ^= MEMFROB_VALUE;
		i++;
	}
	return (s);
}

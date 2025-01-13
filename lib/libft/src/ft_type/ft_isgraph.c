#include <ft.h>

int	ft_isgraph(int c)
{
	if (ft_isprint(c) && c != ' ')
		return (1);
	return (0);
}

#include <ft.h>

int	ft_iscntrl(int c)
{
	if (ft_isascii(c) && !ft_isprint(c))
		return (1);
	return (0);
}

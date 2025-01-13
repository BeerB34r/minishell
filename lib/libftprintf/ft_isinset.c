/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_isinset.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/13 21:24:14 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/13 21:25:22 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

int	ft_isinset(int c, const char *set)
{
	const unsigned char	chr = (unsigned char)c;
	int					i;

	i = -1;
	while (set[++i])
		if (chr == set[i])
			return (i);
	return (-1);
}

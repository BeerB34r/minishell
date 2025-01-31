/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_vector_elem.c                                  :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:31:23 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:31:24 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

void	*ft_vector_get_elem(t_vector *vector, size_t index)
{
	void	*offset;

	if (vector == NULL)
		return (NULL);
	if (index >= vector->size)
		return (NULL);
	offset = (char *)(vector->contents) + index * vector->elem_size;
	return (offset);
}

void	ft_vector_delete_last(t_vector *vector)
{
	if (vector == NULL)
		return ;
	if (vector->size == 0)
		return ;
	vector->clean_elem(ft_vector_get_elem(vector, vector->size - 1));
	vector->size--;
}

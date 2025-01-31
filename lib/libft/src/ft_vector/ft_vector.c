/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_vector.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:31:03 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:31:06 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

#define INITIAL_CAPACITY 128

bool	ft_init_vector(
	t_vector *vector, size_t elem_size, void (*clean_elem)(void *))
{
	vector->capacity = INITIAL_CAPACITY;
	vector->elem_size = elem_size;
	vector->size = 0;
	vector->contents = ft_calloc(vector->capacity, elem_size);
	if (vector->contents == NULL)
		return (false);
	vector->clean_elem = clean_elem;
	return (true);
}

void	ft_delete_vector(t_vector *vector)
{
	size_t	i;

	if (vector == NULL)
		return ;
	i = 0;
	while (i < vector->size)
	{
		if (vector->clean_elem)
			vector->clean_elem(ft_vector_get_elem(vector, i));
		i++;
	}
	vector->clean_elem = NULL;
	vector->capacity = 0;
	vector->elem_size = 0;
	vector->size = 0;
	ft_free(vector->contents);
	vector->contents = NULL;
}

static bool	safe_realloc(t_vector *vector)
{
	void	*new_contents;

	new_contents = ft_calloc(vector->capacity, vector->elem_size);
	if (new_contents == NULL)
	{
		ft_delete_vector(vector);
		return (false);
	}
	ft_memmove(new_contents,
		vector->contents, vector->size * vector->elem_size);
	ft_free(vector->contents);
	vector->contents = new_contents;
	return (true);
}

static bool	clean_return(t_vector *vector, const void *element)
{
	if (vector->clean_elem)
		vector->clean_elem((void *)element);
	return (false);
}

bool	ft_append_vector(t_vector *vector, const void *element)
{
	void	*offset;

	if (vector == NULL)
		return (false);
	if (vector->size + 1 >= vector->capacity)
	{
		if (vector->capacity > SIZE_MAX / 2)
			return (clean_return(vector, element));
		vector->capacity *= 2;
		if (!safe_realloc(vector))
			return (clean_return(vector, element));
	}
	if (vector->size > SIZE_MAX / vector->elem_size)
		return (clean_return(vector, element));
	offset = (char *)(vector->contents) + vector->size * vector->elem_size;
	ft_memcpy(offset, element, vector->elem_size);
	vector->size++;
	return (true);
}

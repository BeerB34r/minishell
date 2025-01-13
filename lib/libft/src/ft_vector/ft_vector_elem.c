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

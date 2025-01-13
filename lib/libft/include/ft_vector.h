#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stddef.h>
# include <stdbool.h>

typedef void(t_cleanf)(void *);
typedef void(t_deletef)(void *);

typedef struct s_vector
{
	size_t	elem_size;
	size_t	size;
	size_t	capacity;
	void	*contents;

	void	(*clean_elem)(void *);
}	t_vector;

bool	ft_init_vector(t_vector *vector, size_t elem_size, t_cleanf clean_elem);
void	ft_delete_vector(t_vector *vector);
bool	ft_append_vector(t_vector *vector, const void *element);
void	*ft_vector_get_elem(t_vector *vector, size_t index);
void	ft_vector_delete_last(t_vector *s_vector);

#endif

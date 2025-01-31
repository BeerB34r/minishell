/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_data_structs.h                                 :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:21:18 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:21:20 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DATA_STRUCTS_H
# define FT_DATA_STRUCTS_H

# include <stdbool.h>
# include <stddef.h>

// used to do nothing with contents
void	ft_do_nothing(void *content);

typedef struct s_ft_list
{
	void	*head;
	void	(*del_content)(void *);
	bool	allow_null;
}	t_ft_list;

void	ft_init_list(t_ft_list *list,
			void (*del_content)(void *), bool allow_null);
bool	ft_copy_list(t_ft_list *dst, const t_ft_list *src,
			void *(*cp_content)(void *));
void	ft_destroy_list(t_ft_list *list);

bool	ft_list_push_front(t_ft_list *list, void *data);
bool	ft_list_push_back(t_ft_list *list, void *data);
void	*ft_list_pop_front(t_ft_list *list);
void	*ft_list_pop_back(t_ft_list *list);

size_t	ft_list_size(t_ft_list *list);
void	*ft_list_first(t_ft_list *list);
void	*ft_list_last(t_ft_list *list);
void	*ft_list_at(t_ft_list *list, size_t index);
void	*ft_list_reverse(t_ft_list *list);

typedef struct s_rb_tree
{
	void	*root;
	void	(*del_key)(void *);
	void	(*del_val)(void *);
	int		(*cmpf)(void *, void *);
}	t_rb_tree;

void	ft_init_rb_tree(t_rb_tree *tree, void (*del_key)(void *),
			void (*del_val)(void *), int (*cmpf)(void *, void *));
bool	ft_copy_rb_tree(t_rb_tree *dst, const t_rb_tree *src,
			void *(*cp_key)(void *), void *(*cp_val)(void *));
void	ft_destroy_rb_tree(t_rb_tree *tree);

bool	ft_add_to_rb_tree(t_rb_tree *tree, void *key, void *value,
			bool rewrite);
void	*ft_get_val_from_rb_tree(t_rb_tree *tree, void *key);

#endif

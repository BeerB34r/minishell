/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_insert_rb_item.c                               :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:25:09 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:25:11 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

static t_rb_node	*find_and_create(t_rb_node **root, t_rb_node *parent,
						t_rb_node_item item, int (*cmpf)(void *, void *))
{
	if (*root == NULL)
	{
		*root = ft_create_rb_node(item);
		if (*root == NULL)
			return (NULL);
		(*root)->parent = parent;
		return (*root);
	}
	if (cmpf(item.key, (*root)->item.key) < 0)
		return (find_and_create(&((*root)->left), *root, item, cmpf));
	return (find_and_create(&((*root)->right), *root, item, cmpf));
}

t_rb_node	*ft_insert_rb_item(t_rb_node *root, t_rb_node_item item,
				int (*cmpf)(void *, void *))
{
	t_rb_node	*new_node;

	new_node = find_and_create(&root, NULL, item, cmpf);
	if (new_node == NULL)
		return (NULL);
	ft_balance_rb_tree_insert(new_node);
	return (ft_rb_root(new_node));
}

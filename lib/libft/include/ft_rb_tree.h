/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_rb_tree.h                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:22:57 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:22:59 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RB_TREE_H
# define FT_RB_TREE_H

typedef enum e_rb_node_color
{
	RB_NODE_RED,
	RB_NODE_BLACK,
}	t_rb_node_color;

typedef struct s_rb_node_item
{
	void	*key;
	void	*value;
}	t_rb_node_item;

typedef struct s_rb_node
{
	struct s_rb_node	*parent;
	struct s_rb_node	*left;
	struct s_rb_node	*right;
	t_rb_node_color		color;
	t_rb_node_item		item;
}	t_rb_node;

t_rb_node	*ft_create_rb_node(t_rb_node_item item);
t_rb_node	*ft_insert_rb_item(t_rb_node *root, t_rb_node_item item,
				int (*cmpf)(void *, void *));
t_rb_node	*ft_search_rb_item(t_rb_node *root, void *key,
				int (*cmpf)(void *, void *));
t_rb_node	*ft_delete_rb_node(t_rb_node *node,
				void (*del_key)(void *), void (*del_val)(void *));
void		ft_delete_rb_tree(t_rb_node *root,
				void (*del_key)(void *), void (*del_val)(void *));

void		ft_balance_rb_tree_insert(t_rb_node *node);
void		ft_balance_rb_tree_delete(t_rb_node *node);

t_rb_node	*ft_rb_node_grandparent(const t_rb_node *node);
t_rb_node	*ft_rb_node_parent_sibling(const t_rb_node *node);
t_rb_node	*ft_rb_node_sibling(const t_rb_node *node);

t_rb_node	*ft_rb_root(const t_rb_node *node);
t_rb_node	*ft_rb_min(const t_rb_node *node);
t_rb_node	*ft_rb_max(const t_rb_node *node);

void		ft_rb_node_rotate_left(t_rb_node *node);
void		ft_rb_node_rotate_right(t_rb_node *node);
void		ft_rb_node_transplant(t_rb_node *node, t_rb_node *child);

#endif

#include <ft.h>

t_rb_node	*ft_rb_node_grandparent(const t_rb_node *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	return (node->parent->parent);
}

t_rb_node	*ft_rb_node_parent_sibling(const t_rb_node *node)
{
	return (ft_rb_node_sibling(node->parent));
}

t_rb_node	*ft_rb_node_sibling(const t_rb_node *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}

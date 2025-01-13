#include <ft.h>

void	ft_balance_rb_tree_delete(t_rb_node *node)
{
	t_rb_node	*s;

	if (node == NULL || node->parent == NULL)
		return ;
	s = ft_rb_node_sibling(node);
	if (s != NULL && s->color == RB_NODE_RED)
	{
		node->parent->color = RB_NODE_RED;
		s->color = RB_NODE_BLACK;
		if (node == node->parent->left)
			ft_rb_node_rotate_left(node->parent);
		else
			ft_rb_node_rotate_right(node->parent);
	}
	// TODO balancing
}

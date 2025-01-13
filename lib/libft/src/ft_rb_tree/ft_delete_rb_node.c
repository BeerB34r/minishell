#include <ft.h>

static void	exchange_items(t_rb_node *node, t_rb_node *descendant)
{
	t_rb_node_item	item;

	item = node->item;
	node->item = descendant->item;
	descendant->item = item;
}

static void	replace_with_child(t_rb_node *node)
{
	if (node->right)
		ft_rb_node_transplant(node, node->right);
	else if (node->left)
		ft_rb_node_transplant(node, node->left);
	else if (node->parent && node->parent->left == node)
		node->parent->left = NULL;
	else if (node->parent && node->parent->right == node)
		node->parent->right = NULL;
}

t_rb_node	*ft_delete_rb_node(t_rb_node *node,
				void (*del_key)(void *), void (*del_val)(void *))
{
	t_rb_node	*descendant;
	t_rb_node	*to_balance;

	if (node == NULL)
		return (NULL);
	if (node->left && node->right)
		descendant = ft_rb_min(node->right);
	else
		descendant = node;
	exchange_items(node, descendant);
	replace_with_child(descendant);
	to_balance = descendant->parent;
	ft_balance_rb_tree_delete(to_balance);
	del_key(descendant->item.key);
	del_val(descendant->item.value);
	ft_free(descendant);
	if (to_balance->color == RB_NODE_RED)
		to_balance->color = RB_NODE_BLACK;
	else
		ft_balance_rb_tree_delete(to_balance);
	return (ft_rb_root(to_balance));
}

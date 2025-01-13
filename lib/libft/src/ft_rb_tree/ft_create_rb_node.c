#include <ft.h>

t_rb_node	*ft_create_rb_node(t_rb_node_item item)
{
	t_rb_node	*result;

	result = (t_rb_node *)ft_malloc(sizeof(t_rb_node));
	if (result == NULL)
		return (NULL);
	result->parent = NULL;
	result->left = NULL;
	result->right = NULL;
	result->color = RB_NODE_RED;
	result->item = item;
	return (result);
}

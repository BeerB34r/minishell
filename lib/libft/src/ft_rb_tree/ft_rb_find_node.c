#include <ft.h>

t_rb_node	*ft_rb_root(const t_rb_node *node)
{
	t_rb_node	*result;

	result = (t_rb_node *)node;
	if (result == NULL)
		return (NULL);
	while (result->parent != NULL)
		result = result->parent;
	return (result);
}

t_rb_node	*ft_rb_min(const t_rb_node *node)
{
	t_rb_node	*result;

	result = (t_rb_node *)node;
	if (result == NULL)
		return (NULL);
	while (result->left != NULL)
		result = result->left;
	return (result);
}

t_rb_node	*ft_rb_max(const t_rb_node *node)
{
	t_rb_node	*result;

	result = (t_rb_node *)node;
	if (result == NULL)
		return (NULL);
	while (result->right != NULL)
		result = result->right;
	return (result);
}

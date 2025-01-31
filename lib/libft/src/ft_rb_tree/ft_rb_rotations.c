/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_rb_rotations.c                                 :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:26:05 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:26:07 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

void	ft_rb_node_rotate_left(t_rb_node *node)
{
	t_rb_node	*pivot;

	pivot = node->right;
	ft_rb_node_transplant(node, pivot);
	node->right = pivot->left;
	if (pivot->left != NULL)
		pivot->left->parent = node;
	pivot->left = node;
}

void	ft_rb_node_rotate_right(t_rb_node *node)
{
	t_rb_node	*pivot;

	pivot = node->left;
	ft_rb_node_transplant(node, pivot);
	node->left = pivot->right;
	if (pivot->right != NULL)
		pivot->right->parent = node;
	pivot->right = node;
}

void	ft_rb_node_transplant(t_rb_node *node, t_rb_node *child)
{
	child->parent = node->parent;
	if (node->parent != NULL)
	{
		if (node == node->parent->left)
			node->parent->left = child;
		else
			node->parent->right = child;
	}
	node->parent = child;
}

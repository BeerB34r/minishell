/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_balance_rb_tree_insert.c                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:24:27 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:24:28 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

static void	try_balance_line(t_rb_node *node)
{
	t_rb_node	*g;

	g = ft_rb_node_grandparent(node);
	if (node == node->parent->right)
		ft_rb_node_rotate_left(g);
	else
		ft_rb_node_rotate_right(g);
	node->parent->color = RB_NODE_BLACK;
	g->color = RB_NODE_RED;
}

static void	try_balance_triangle(t_rb_node *node)
{
	t_rb_node	*g;

	g = ft_rb_node_grandparent(node);
	if (node == node->parent->right && node->parent == g->left)
	{
		ft_rb_node_rotate_left(node->parent);
		node = node->left;
	}
	else if (node == node->parent->left && node->parent == g->right)
	{
		ft_rb_node_rotate_right(node->parent);
		node = node->right;
	}
	try_balance_line(node);
}

static void	try_balance_red_parent_sibling(t_rb_node *node)
{
	t_rb_node	*ps;
	t_rb_node	*g;

	ps = ft_rb_node_parent_sibling(node);
	if (ps != NULL && ps->color == RB_NODE_RED)
	{
		node->parent->color = RB_NODE_BLACK;
		ps->color = RB_NODE_BLACK;
		g = ft_rb_node_grandparent(node);
		g->color = RB_NODE_RED;
		ft_balance_rb_tree_insert(g);
	}
	else
		try_balance_triangle(node);
}

void	ft_balance_rb_tree_insert(t_rb_node *node)
{
	if (node->parent == NULL)
		node->color = RB_NODE_BLACK;
	else if (node->parent->color == RB_NODE_RED)
		try_balance_red_parent_sibling(node);
}

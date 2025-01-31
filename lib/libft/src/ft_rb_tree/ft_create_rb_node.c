/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_create_rb_node.c                               :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/31 17:24:45 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/31 17:24:48 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

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

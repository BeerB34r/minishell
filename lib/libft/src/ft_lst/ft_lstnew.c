/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: misiren <misiren@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 20:02:26 by misiren       #+#    #+#                 */
/*   Updated: 2024/10/07 20:16:12 by misiren       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (elem == NULL)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

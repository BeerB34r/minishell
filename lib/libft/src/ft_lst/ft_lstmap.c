/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: misiren <misiren@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 20:02:26 by misiren       #+#    #+#                 */
/*   Updated: 2024/10/07 20:57:12 by misiren       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new_node;
	void	*content;

	head = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (new_node == NULL)
		{
			ft_lstclear(&head, del);
			del(content);
			return (head);
		}
		ft_lstadd_back(&head, new_node);
		lst = lst->next;
	}
	return (head);
}

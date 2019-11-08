/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:27:28 by cpierce           #+#    #+#             */
/*   Updated: 2019/09/19 21:11:45 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*add;

	if (!(add = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	add = f(lst);
	if (lst->next)
	{
		add->next = ft_lstmap(lst->next, f);
		if (add->next == NULL)
		{
			free(add);
			return (NULL);
		}
	}
	else
		add->next = NULL;
	return (add);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 03:05:54 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/18 07:32:06 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	del(t_list *item, t_list *prev)
{
	if (prev && item->next)
		prev->next = item->next;
	else if (prev && !item->next)
		prev->next = NULL;
	item->content = NULL;
	item->content_size = 0;
	item->next = NULL;
	free(item);
}

void		remove_hidden(t_list **items)
{
	t_list	*cur;
	t_list	*nxt;
	t_list	*prev;

	cur = *items;
	prev = NULL;
	if(!cur)
		return ;
	while(cur)
	{
		nxt = cur->next;
		if (((struct dirent *)(cur->content))->d_name[0] == '.')
			del(cur, prev);
		cur = nxt;
	}
}

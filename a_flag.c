/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 03:05:54 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/20 02:51:51 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/*
static void	del(t_list **item, t_list **prev)
{
	if (*prev && (*item)->next)
		(*prev)->next = (*item)->next;
	else if (*prev && !(*item)->next)
		(*prev)->next = NULL;
	(*item)->content = NULL;
	(*item)->content_size = 0;
	(*item)->next = NULL;
	free(*item);
	*item = NULL;
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
			del(&cur, &prev);
		prev = cur;
		cur = nxt;
	}
}
*/
static void	del(t_list **prev, t_list **cur)
{
	if(*prev && (*cur)->next)
		(*prev)->next = (*cur)->next;
	if (*prev && !(*cur)->next)
		(*prev)->next = NULL;
	free((*cur)->content);
	(*cur)->content = NULL;
	(*cur)->content_size = 0;
	free(*cur);
}

void		remove_hidden(t_list **items)
{
	t_list	*cur;
	t_list	*prev;
	t_list	*nxt;
	int		first;

	first = 1;
	cur = *items;
	prev = NULL;
	nxt = NULL;
	while(cur)
	{
		nxt = cur->next;
		if (((struct dirent *)(cur->content))->d_name[0] == '.')
			del(&prev, &cur);

		else
		{
			if (first)
			{
				*items = cur;
				first = 0;
			}
			prev = cur;
		}
		cur = nxt;
	}
}

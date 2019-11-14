/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 02:58:05 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/13 22:41:28 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	rev_list(t_list **items)
{
	t_list	*cur;
	t_list	*nxt;
	t_list	*prev;

	cur = *items;
	prev = NULL;
	if (!cur)
		return ;
	nxt = cur->next;
	while (nxt)
	{
		cur->next = prev;
		nxt->next = cur;
		prev = cur;
		cur = nxt;
		nxt = nxt->next;
	}
}

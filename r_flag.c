/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 02:58:05 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/18 07:33:49 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	rev_list(t_list **items)
{
	t_list	*cur;
	t_list	*nxt;
	t_list	*prev;
	t_list	*nxt2;

	cur = *items;
	prev = NULL;
	if (!cur)
		return ;
	nxt = cur->next;
	while (nxt)
	{
		cur->next = prev;
        nxt2 = nxt->next;
		nxt->next = cur;
		prev = cur;
		cur = nxt;
		nxt = nxt2;
	}
	*items = cur;
}

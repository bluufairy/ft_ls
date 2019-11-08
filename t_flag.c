/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 01:56:38 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/08 03:02:30 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 	comp_time(struct dirent a, struct dirent b)
{
	struct stat		*a_stat;
	struct stat		*b_stat;
	struct timespec	a_time;
	struct timespec	b_time;

	if (!stat(a->d_name, a_stat) && !stat(d->d_name, d_stat)) //missing full path name?
	{
		a_time = a_stat->st_mtim;
		b_time = a_stat->st_mtim;
		if (a_time.tv_sec > b_time.tv_sec)
			return (1);
		else
			return (0);
	}
	else
		exit (0);
}

void	time_sort(t_list **items)
{
	t_list			*cur;
	t_list			*nxt;

	cur = *items;
	nxt = cur->next;
	if (!cur)
		return ;
	while(cur->next)
	{
		if (comp_time(cur->data, nxt->data))
		{
			cur->next = nxt->next;
			nxt->next = cur;
			cur = *items;
		}
		else
			cur = cur->next;
	}
}

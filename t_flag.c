/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 01:56:38 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/21 10:50:22 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char *p(struct dirent *name, char *path)
{
	char *res;

	res = str_join_free3(path, "/", name->d_name);
	return (res);
}

int		comp_time(t_list *a, t_list *b, char *path)
{
	struct stat		a_stat;
	struct stat		b_stat;
	struct timespec	a_time;
	struct timespec	b_time;

	if (!stat(p(((struct dirent *)(a->content)), path), &a_stat) &&
			!stat(p(((struct dirent *)(b->content)), path), &b_stat))
	{
		a_time = a_stat.st_mtimespec;
		b_time = b_stat.st_mtimespec;
		if (a_time.tv_sec > b_time.tv_sec)
			return (1);
		else if (a_time.tv_sec < b_time.tv_sec)
			return (0);
		else if (a_time.tv_sec == b_time.tv_sec)
		{
			if (a_time.tv_nsec > b_time.tv_nsec)
				return (1);
			else if (a_time.tv_nsec < b_time.tv_nsec)
				return (0);
			else
				return (ft_strcmp(((struct dirent *)(a->content))->d_name,
							((struct dirent *)(b->content))->d_name) > 0);
		}
	}
	return (0);
}

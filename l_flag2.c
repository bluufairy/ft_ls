/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_flag2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 22:45:00 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/13 22:49:07 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_group(struct stat *extra)
{
	struct group *grp;

	grp = getgrgid(extra->st_gid);
	return (grp->gr_name);
}

char	*get_size(struct stat *extra)
{
	int				s;
	char			*res;
	char			*old;

	s = (int)extra->st_size;
	res = ft_itoa(s);
	old = res;
	res = ft_strjoin(res, " ");
	free(res);
	return (res);
}

char	*get_timeandname(struct stat *extra, struct dirent file)
{
	struct timespec	t;
	char			*res;
	char			*old;
	
	t = extra->st_mtimespec;
	res = ctime(&t.tv_sec);
	old = res;
	res = ft_strjoin(res, " ");
	free(old);
	old = res;
	res = ft_strjoin(res, file.d_name);
	free(old);
	return (res);
}

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
	return (ft_strjoin(grp->gr_name, " "));
}

char	*get_links(struct stat *extra)
{
	char		*res;
	int			l;
	
	l = (int)extra->st_nlink;
	res = ft_strjoin(ft_itoa(l), " ");
	return (res);
}

char	*get_size(struct stat *extra)
{
	int				s;
	char			*res;
	char			*old;

	s = (int)extra->st_size;
	res = ft_itoa(s);
	old = res;
	res = ft_strjoin(res, "\t");
	free(res);
	return (res);
}

char	*replace_end(char *str)
{
	int				i;
	int				i2;
	char			*res;

	res = ft_strdup(str);
	res = (char *)malloc(sizeof(char) * (ft_strlen(str) - 3));
	i = 3;
	i2 = 0;
	while (str[i])
	{
		res[i2] = str[i];
		i++;
		i2++;
	}
	while (res[i] != ':')
		i--;
	res[i] = ' ';
	res[i + 1] = '\0';
	return (res);
}

char	*get_timeandname(struct stat *extra, struct dirent file)
{
	struct timespec	t;
	char			*res;
	char			*old;
	
	t = extra->st_mtimespec;
	res = replace_end(ctime(&t.tv_sec));
	old = res;
	res = ft_strjoin(res, file.d_name);
	free(old);
	old = res;
	res = ft_strjoin(res, "\n");
	free(old);
	return (res);
}

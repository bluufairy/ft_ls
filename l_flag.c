/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 03:29:16 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/13 23:13:24 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*get_permissions(struct stat *extra, struct dirent *item)
{
	char		*add;
	char		*res;
	char		*ch;
	size_t		i;

	ch = "rwxrwxrwx";
	i = 0;
	res = (char *)malloc(sizeof(char) * 12);
	res[11] = '\0';
	res[10] = ' ';
	if (is_dir(*item))
		res[0] = 'd';
	if (S_ISLNK(extra->st_mode))
		res[0] = 'l';
	else
		res[0] = '-';
	while (i < 9)
	{
		res[i + 1] = (extra->st_mode & (1 << (8 - i))) ? ch[i] : '-';
		i++;
	}
	return (res);
}

static char	*get_links(struct stat *extra)
{
	char		*res;
	int			l;
	
	l = (int)extra->st_nlink;
	res = ft_strjoin(ft_itoa(l), " ");
	return (res);
}

static char	*get_owner(struct stat *extra)
{
	struct passwd *user;

	user = getpwuid(extra->st_uid);
	return (user->pw_name);
}

static char	*makestr(struct dirent *item)
{
	struct stat	*extra;
	char		*path;
	char		*res;
	char		*old;

	path = ft_strjoin("./", item->d_name);
	if(stat(path, extra))
		exit (0);
	free(path);
	res = get_permissions(extra, item);
	old = res;
	res = ft_strjoin(res, get_links(extra));
	free(old);
	old = res;
	res = ft_strjoin(res, get_owner(extra));
	free(old);
	old = res;
	res = ft_strjoin(res, get_group(extra));
	free(old);
	old = res;
	res = ft_strjoin(res, get_size(extra));
	free(old);
	old = res;
	res = ft_strjoin(res, get_timeandname(extra, *item));
	free(old);
	return (res);
}

char		**l_trans(t_list **items)
{
	int			l;
	char		**res;
	t_list		*cur;
	int			i;
	char		*old;

	l = list_length(items);
	res = (char **)malloc(sizeof(char *) + 1);
	res[l] = NULL;
	i = 0;
	cur = *items;
	while(cur)
	{
		res[i] = makestr(cur->content);
		old = res[i];
		res[i] = ft_strjoin(res[i], cur->content.d_name);
		free(old);
		i++;
		cur = cur->next;
	}
	return (res);
}

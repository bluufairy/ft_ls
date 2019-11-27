/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 03:29:16 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/14 01:22:38 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	xattr(char *path, struct dirent *item)
{
	acl_t		acl = NULL;
	acl_entry_t x;
	ssize_t		res;
	char		*full_path;

	full_path = str_join_free3(path, "/", item->d_name);

	acl = acl_get_link_np(full_path, ACL_TYPE_EXTENDED);
	if (acl_get_entry(acl, ACL_FIRST_ENTRY, &x) == -1 && acl)
	{
		acl_free(acl);
		acl = NULL;
	}
	res = listxattr(full_path, NULL, 0, XATTR_NOFOLLOW);
	if (res > 0)
		return '@';
	else if (acl)
		return '+';
	else
		return ' ';
}

static char	*get_permissions(struct stat *extra, struct dirent *item, char *p)
{
	char		*add;
	char		*res;
	char		*ch;
	size_t		i;

	ch = "rwxrwxrwx";
	i = 0;
	res = (char *)malloc(sizeof(char) * 14);
	res[12] = '\0';
	res[11] = ' ';
	if (is_dir(*item, p)) //need to replace res with path name
		res[0] = 'd';
	else
		res[0] = '-';
	res[10] = xattr(p, item);
	//res[10] =  (listxattr(ft_strjoin(p, item->d_name), NULL, 0, XATTR_NOFOLLOW) > 0) ? ' ' : 'l';
	//if (S_ISLNK(extra->st_mode))
	//if (extra->st_codepage)
	//	res[10] = '\0' + 64;
	//else
	//	res[10] = ' ';	
	while (i < 9)
	{
		res[i + 1] = (extra->st_mode & (1 << (8 - i))) ? ch[i] : '-';
		i++;
	}
	return (res);
}

static char	*get_owner(struct stat *extra)
{
	struct passwd *user;

	user = getpwuid(extra->st_uid);
	return (ft_strjoin(user->pw_name, "  "));
}

static char	*makestr(struct dirent *item, char *path)
{
	struct stat	extra;
	char		*p;
	char		*res;
	char		*old;

	//path = ft_strjoin("./", item->d_name);
	p = str_join_free3(path, "/", item->d_name);
	if(stat(p, &extra))
		exit (0);
	res = get_permissions(&extra, item, path);
	old = res;
	res = ft_strjoin(res, get_links(&extra));
	free(old);
	old = res;
	res = ft_strjoin(res, get_owner(&extra));
	free(old);
	old = res;
	res = ft_strjoin(res, get_group(&extra));
	free(old);
	old = res;
	res = ft_strjoin(res, get_size(&extra));
	free(old);
	old = res;
	res = ft_strjoin(res, get_timeandname(&extra, *item));
	free(old);
	free(p);
	return (res);
}

char		**l_trans(t_list **items, ls_data *data, int index)
{
	int			l;
	char		**res;
	t_list		*cur;
	int			i;
	char		*old;

	l = list_length(items);
	res = (char **)malloc(sizeof(char *) * (l + 1));
	res[l] = NULL;
	i = 0;
	cur = *items;
	while(cur)
	{
		res[i] = makestr(cur->content, data->path[index]);
		//old = res[i];
		//res[i] = ft_strjoin(res[i], ((struct dirent *)cur->content)->d_name);
		//free(old);
		i++;
		cur = cur->next;
	}
	return (res);
}

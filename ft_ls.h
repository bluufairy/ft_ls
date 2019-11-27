/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:14:42 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/26 21:52:06 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/xattr.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/acl.h>

typedef struct	flags
{
	char	valid;
	char	*valid2;
	int		l_flag;
	int		R_flag;
	int		a_flag;
	int		r_flag;
	int		t_flag;
	char	**path;
}				ls_data;

char	*get_links(struct stat *extra);
void	path_name(char *path);
char	*str_join_free3(char *a, char *b, char *c);
void	merge_sort(t_list **items, int (*compare)(t_list *, t_list *, char *),
			int rev, char *path);
int		adddir(ls_data *data, int index, char *name, int c);
int		comp_alpha(t_list *a, t_list *b, char *path);
void	ls_out(ls_data dat);
//void	alpha_sort(t_list **items);
char	**l_trans(t_list **items, ls_data *data, int index);
int		comp_time(t_list *a, t_list *b, char *path);
void	rev_list(t_list **items);
void	remove_hidden(t_list **items);
char	**reg_trans(t_list **items);
int		list_length(t_list **items);
int		is_dir(struct dirent item, char *path);
char	*get_group(struct stat *extra);
char	*get_size(struct stat *extra);
char	*get_timeandname(struct stat *extra, struct dirent file);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:14:42 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/13 22:52:09 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include "libft/libft.h"
#include <sys/types.h>
#include <grp.h>
#include <pwd.h>
#include <sys/stat.h>

typedef struct	flags
{
	char	valid;
	int		l_flag;
	int		R_flag;
	int		a_flag;
	int		r_flag;
	int		t_flag;
	char	**path;
}				ls_data;

void	ls_out(ls_data dat);
void	time_sort(t_list **items);
void	rev_list(t_list **items);
void	remove_hidden(t_list **items);
char	**reg_trans(t_list **items);
int		list_length(t_list **items);
int		is_dir(struct dirent item);
char	*get_group(struct stat *extra);
char	*get_size(struct stat *extra);
char	*get_timeandname(struct stat *extra, struct dirent file);

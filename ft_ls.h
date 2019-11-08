/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:14:42 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/08 04:04:43 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include "libft/libft.h"

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
char	**reg_trans(**t_list items);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 01:28:59 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/20 06:47:00 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>


int				comp_alpha(t_list *a, t_list *b, char *path)
{
	char	*a_name;
	char	*b_name;
	int		res;
	int		i;
	
	if (path)
		path = path;
	res = 0;
	i = 0;
	a_name = ((struct dirent *)(a->content))->d_name;
	b_name = ((struct dirent *)(b->content))->d_name;
	if (ft_strcmp(a_name, b_name) < 0)
		return 1;
	else
		return 0;
}

static void	split(t_list **head, t_list **left, t_list **right)
{
	t_list *fast = (*head)->next;
	t_list *slow = *head;
	
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*left = *head;
	*right = slow->next;
	slow->next = NULL;
}

t_list		*merge(t_list *left, t_list *right,
				int (*comp)(t_list *, t_list *, char *), int rev, char *path)
{
	t_list		*res;
	
	if (left == NULL)
		return right;
	if (right == NULL)
		return left;
	res = NULL;
	if (rev ? comp(right, left, path) : comp(left, right, path))
	{
		res = left;
		res->next = merge(left->next, right, comp, rev, path);
	}
	else
	{
		res = right;
		res->next = merge(left, right->next, comp, rev, path);
	}
	return (res);
}

void		merge_sort(t_list **items,int (*compare)(t_list *, t_list *, char *),
				int rev, char *path)
{
	t_list		*head;
	t_list		*left;
	t_list		*right;

	if (!*items || !(*items)->next)
		return ;
	left = NULL;
	right = NULL;
	head = *items;
	split(&head, &left, &right);
	merge_sort(&left, compare, rev, path);
	merge_sort(&right, compare, rev, path);
	head = merge(left, right, compare, rev, path);
	*items = head;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 01:28:59 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/20 04:58:05 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>


int				comp_alpha(t_list *a, t_list *b)
{
	char	*a_name;
	char	*b_name;
	int		res;
	int		i;

	res = 0;
	i = 0;
	a_name = ((struct dirent *)(a->content))->d_name;
	b_name = ((struct dirent *)(b->content))->d_name;
	if (ft_strcmp(a_name, b_name) < 0)
	{
	//	printf("moving %s above %s\n", a_name, b_name);
		return 1;
	}
	else
	{
	//	printf("not swapping %s and %s\n", a_name, b_name);
		return 0;
	}
	/*
	while (a_name[i] == b_name[i] && a_name[i] && b_name[i])
		i++;
	if (b_name[i] > a_name[i])
		return 1;
	else
		return 0;
	*/
}

static void	split(t_list **head, t_list **left, t_list **right, int mid_l)
{
	/*
	int			i;

	*left = *head;
	while (*left && i < mid_l)
	{
		*left = (*left)->next;
		i++;
	}
	if (!*left)
		return ;
	*right = (*left)->next;
	(*left)->next = NULL;
	*left = *head;
	*/
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

t_list		*merge(t_list *left, t_list *right, int (*comp)(t_list *, t_list *))
{
	t_list		*res;
	
	if (left == NULL)
		return right;
	if (right == NULL)
		return left;
	res = NULL;
	//printf("yo\n");
	if (comp(left, right))
	{
		res = left;
		res->next = merge(left->next, right, comp);
	}
	else
	{
		res = right;
		res->next = merge(left, right->next, comp);
	}
	return (res);
}

void		merge_sort(t_list **items, int (*compare)(t_list *, t_list *))
{
	t_list		*head;
	t_list		*left;
	t_list		*right;
	int			mid_l;

	if (!*items || !(*items)->next)
		return ;
	left = NULL;
	right = NULL;
	head = *items;
	mid_l = 0;//(list_length(&head) / 2) + (list_length(&head) % 2);
	//printf("midl: %d\n", mid_l);
	split(&head, &left, &right, mid_l);
	merge_sort(&left, compare);
	merge_sort(&right, compare);
	head = merge(left, right, compare);
	*items = head;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 01:33:37 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/18 19:57:22 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	comp_alpha(t_list *a, t_list *b)
{
	char	*a_name;
	char	*b_name;
	int		res;
	int		i;

	res = 0;
	i = 0;
	a_name = ((struct dirent *)(a->content))->d_name;
	b_name = ((struct dirent *)(b->content))->d_name;
	while (a_name[i] == b_name[i] && a_name[i] && b_name[i])
		i++;
	if (b_name[i] > a_name[i])
		return 1;
	else
		return 0;
}

static void		split(t_list *ref, t_list **a, t_list **b, int l)
{
	int 	i;

	i = 0;
	*a = ref;
	while (i < l)
	{
		*a = (*a)->next;
		i++;
	}
	*b = (*a)->next;
	(*a)->next = NULL;
}

static t_list	*merge(t_list *a, t_list *b)
{
	t_list	*res;

	res = NULL;
	if (!a)
		return (b);
	if (!b)
		return (a);
	if (comp_alpha(a, b))
	{
		res = a;
		res->next = merge(a->next, b);
	}
	else
	{
		res = b;
		res->next = merge(a, b->next);
	}
	return (res);
}

static int		merge_len(t_list *group)
{
	int		count;
	t_list	*cur;

	count = 0;
	cur = group;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return (count);
}

void			 merge_sort(t_list **start)
{
	t_list	*ref;
	t_list	*a;
	t_list	*b;
	int		len_ref;

	ref = *start;
	if (!(ref))
		return ;
	if (!(ref->next))
		return ;
	len_ref = merge_len(ref) / 2;
	split(ref, &a, &b, len_ref);
	merge_sort(&a);
	merge_sort(&b);
	ref = merge(a, b);
	start = &ref;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_it.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 04:02:21 by cpierce           #+#    #+#             */
/*   Updated: 2019/11/18 05:02:52 by cpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	swap_item(t_list *a, t_list *b)
{
	t_list	*tmp;
	
	tmp = a;
	a = b;
	b = t;
}

static t_list	**set_sr(t_list *a1, t_list* a2, t_list *b1, t_list *b2, int sz)
{
	int		c;
	t_list	*tmp;
	t_list	**ret;

	ret = (t_list**)malloc(sizeof(t_list*)*2);
	c = siz;
	while (--c && b1->next)
		b1 = b1->next;
	s2 = b1->next;
	if (!s2)
		return (NULL);
	c = siz;
	b2 = s2;
	while (--c && b2->next)
		b2 = b2->next;
	tmp = b2->next;
	combine(&a1, &b1, &a2, &b2);
	ret[0] = b2;
	ret[1] = tmp;
	return (ret);
}
/*
**  OKAY wTF DO I REALLY HAVE TO DO ALL THIS SHIT FOR NORM.  THIS IS NOT 
**	ELEGANT CODE AT ALL.  
*/


static void	merge_sort_it2(t_list **items, t_list *a1, t_list *old_end, int siz)
{
	t_list	*a2;
	t_list	*b1;
	t_list	*b2;
	t_ist	**last;
	int		first;

	a2 = NULL;
	b1 = NULL;
	b2 = NULL;
	while (a1)
	{
		first = (a1 = *items) ? 1 : 0;
		b1 = a1;
		if (!(last = set_sr(a1, a2, b1, b2, siz)))
			break ;
		if (first)
			*items = a1;
		else
			last[0]->next = a1;
		a1 = last[1];

	}
}

void		merge_sort_it(t_list **items, t_list *a1, t_list *a2, t_list *b1)
{
	t_list	*b2;
	t_list	*old_end;
	int		l;
	int		size;

	b2 = NULL;
	old_end = NULL;
	l = list_length(items);
	it (!*items)
		return ;
	while (size < l)
	{
		a1 = *items;
		while(a1)
		{
			merge_sort_it2(items, *a1, *old_end, size);
		}
		size *= 2;
	}
}



OKAY BASICALLY I FUCKED ALL OF THIS UP AND IM GOING TO STOP NOW
 JSKNDKJNSFKJBUFSGUINCKKKSIIBUUBN


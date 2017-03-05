/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 11:47:43 by dgolear           #+#    #+#             */
/*   Updated: 2017/02/27 13:52:17 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		split_list(t_list *head, t_list **front, t_list **back)
{
	t_list	*slow;
	t_list	*fast;

	if (head == NULL || head->next == NULL)
	{
		*front = head;
		*back = NULL;
	}
	else
	{
		slow = head;
		fast = head->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front = head;
		*back = slow->next;
		slow->next = NULL;
	}
}

static t_list	*merge_sort(t_list *a, t_list *b, \
							intmax_t (*compare)(const void *, const void *))
{
	t_list	*result;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (compare(a->content, b->content) <= 0)
	{
		result = a;
		result->next = merge_sort(a->next, b, compare);
	}
	else
	{
		result = b;
		result->next = merge_sort(a, b->next, compare);
	}
	return (result);
}

int				ft_lstsort(t_list **head, \
		intmax_t (*compare)(const void *, const void *))
{
	t_list	*node;
	t_list	*a;
	t_list	*b;

	node = *head;
	if (node == NULL || node->next == NULL)
		return (0);
	split_list(node, &a, &b);
	ft_lstsort(&a, compare);
	ft_lstsort(&b, compare);
	*head = merge_sort(a, b, compare);
	return (0);
}

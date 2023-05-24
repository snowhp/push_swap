/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:56:03 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/24 14:58:21 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sortlist(t_stack **head_a, t_stack **head_b)
{
	int	size;

	if (!ft_listsorted(head_a) || ft_listsize(head_a) == 1)
		ft_exit("List is sorted", 1, head_a, head_b);
	size = ft_listsize(head_a);
	if (size == 2)
		ft_sort2(head_a);
	if (size == 3)
		ft_sort3(head_a);
	if (size == 4 || size == 5)
		ft_sort5(head_a, head_b, size);
	if (size > 5)
	{
		ft_listindex(head_a, 1);
		ft_sort500(head_a, head_b);
	}

}

void	ft_sort2(t_stack **head_a)
{
	if ((*head_a)->next->content < (*head_a)->content)
		ft_rotatedown(head_a, 'a');
}

void	ft_sort3(t_stack **head)
{
	long	f;
	long	s;
	long	t;

	f = (*head)->content;
	s = (*head)->next->content;
	t = (*head)->next->next->content;
	if (f < s && f < t && s > t)
	{
		ft_swap(head, 'a');
		ft_rotateup(head, 'a');
	}
	else if (f > s && f < t && s < t)
		ft_swap(head, 'a');
	else if (f < s && f > t && s > t)
		ft_rotatedown(head, 'a');
	else if (f > s && f > t && s < t)
		ft_rotateup(head, 'a');
	else if (f > s && f > t && s > t)
	{
		ft_swap(head, 'a');
		ft_rotatedown(head, 'a');
	}
}

void	ft_sort5(t_stack **head_a, t_stack **head_b, int size)
{
	t_stack	*min;
	t_stack	*max;

	min = ft_findmin(head_a);
	ft_autopush(min, head_a, head_b, 'b');
	if (size == 5)
	{
		max = ft_findmax(head_a);
		ft_autopush(max, head_a, head_b, 'b');
	}
	ft_sort3(head_a);
	if (size == 5)
	{
		ft_push(head_b, head_a, 'a');
		ft_rotateup(head_a, 'a');
	}
	ft_push(head_b, head_a, 'a');
}

void	ft_sort500(t_stack **head_a, t_stack **head_b)
{
/* 	t_stack	*min;

	while (*head_a)
	{
		min = ft_findmin(head_a);
		ft_autopush(min, head_a, head_b, 'b');
	}
	while (*head_b)
		ft_push(head_b, head_a, 'b'); */
	int		size;

	size = ft_listsize(head_a);
	ft_push(head_a, head_b, 'b');
	ft_push(head_a, head_b, 'b');
	while(ft_listsorted(head_a) && size == ft_listsize(head_a))
		ft_bestmove(head_a, head_b);
}

void	ft_bestmove(t_stack **head_a, t_stack **head_b)
{
	t_stack	*current;

	current = *head_a;
	while (current)
	{

	}
}

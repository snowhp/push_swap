/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:56:03 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/22 14:20:55 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ft_sortlist(t_stack **head_a, t_stack **head_b)
{
	int size;
	(void) head_b;
	size = ft_listsize(head_a);
	ft_printf("List size: %i\n", size);

	if (size == 2)
		ft_sort2(head_a);
	if (size == 3)
		ft_sort3(head_a);
	if (size == 4 || size == 5)
		ft_sort5(head_a, head_b, size);
}

void	ft_sort5(t_stack **head_a, t_stack **head_b, int size)
{
	ft_push(head_a, head_b, 'b');
	if (size == 5)
		ft_push(head_a, head_b, 'b');
	ft_sort3(head_a);
	ft_insertinsortlist(head_a, head_b);
	if (size == 5)
		ft_insertinsortlist(head_a, head_b);
}

void	ft_insertinsortlist(t_stack **head_a, t_stack **head_b)
{
	int	max;
	unsigned int	rotates;

	max = ft_findmax(head_a);
	if ((*head_b)->content > max)
	{
		ft_push(head_b, head_a, 'a');
		ft_rotateup(head_a, 'a');
		return ;
	}
	rotates = 0;
	while((*head_b)->content > (*head_a)->content)
	{
		ft_rotateup(head_a, 'a');
		rotates++;
	}
	ft_push(head_b, head_a, 'a');
	while(rotates--)
		ft_rotatedown(head_a, 'a');
}

int	ft_findmax(t_stack **head)
{
	t_stack *current;
	int		max;

	current = *head;
	max = current->content;
	while(current)
	{
		if (max < current->content)
			max = current->content;
		current = current->next;
	}
	return (max);
}

int	ft_listsize(t_stack **head_a)
{
	t_stack *current;
	int	size;

	size = 0;
	current = *head_a;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	ft_sort2(t_stack **head_a)
{
	if((*head_a)->next->content < (*head_a)->content)
		ft_rotatedown(head_a, 'a');
}

void	ft_sort3(t_stack **head)
{
	long f;
	long s;
	long t;

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

int	ft_listsorted(t_stack **head)
{
	t_stack *current;

	current = *head;
	while (current)
	{
		if(current->next && current->content > current->next->content)
			return (1);
		current = current->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:34:34 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/22 16:30:22 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_autopush(t_stack *n, t_stack **head_o, t_stack **head_d, char c)
{
	char	r;

	if (c == 'b')
		r = 'a';
	if (c == 'a')
		r = 'b';
	if (ft_listpos(n, head_o) <= ft_listsize(head_o) / 2)
	{
		while (n != (*head_o))
			ft_rotateup(head_o, r);
		ft_push(head_o, head_d, c);
	}
	else
	{
		while (n != (*head_o))
			ft_rotatedown(head_o, r);
		ft_push(head_o, head_d, c);
	}
}

t_stack	*ft_findmax(t_stack **head)
{
	t_stack	*current;
	t_stack	*max;

	current = *head;
	max = current;
	while (current)
	{
		if (max->content < current->content)
			max = current;
		current = current->next;
	}
	return (max);
}

t_stack	*ft_findmin(t_stack **head)
{
	t_stack	*current;
	t_stack	*min;

	current = *head;
	min = current;
	while (current)
	{
		if (min->content > current->content)
			min = current;
		current = current->next;
	}
	return (min);
}

int	ft_listpos(t_stack *node, t_stack **head)
{
	t_stack	*current;
	int		pos;

	pos = 0;
	current = *head;
	while (current)
	{
		pos++;
		if (node == current)
			return (pos);
		current = current->next;
	}
	return (pos);
}

int	ft_listsize(t_stack **head)
{
	t_stack	*current;
	int		size;

	size = 0;
	current = *head;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

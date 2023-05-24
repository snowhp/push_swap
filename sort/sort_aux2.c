/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:34:34 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/24 12:59:02 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* void	ft_insertinsortlist(t_stack **head_a, t_stack **head_b)
{
	int	*max;
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
} */

int	ft_listsorted(t_stack **head)
{
	t_stack	*current;

	current = *head;
	while (current)
	{
		if (current->next && current->content > current->next->content)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ft_listindex(t_stack **head, int index)
{
	/* int		index;
	int		content;
	t_stack	*current;

	index = 1;
	content = (*head)->content;
	current = current->next;
	while (current)
	{
		if (current->content < content && !current->index)
			content = current->content;
		if (!current->next)

		current = current->next;
	} */

	t_stack	*current;
	t_stack	*min;

	current = *head;
	min = NULL;
	while (current)
	{
		if (!min && !current->index)
			min = current;
		if (min && !current->index && min->content > current->content)
			min = current;
		current = current->next;
	}
	min->index = index;
	if (ft_islistindex(head) == 0)
		ft_listindex (head, ++index);
}

int	ft_islistindex(t_stack **head)
{
	t_stack	*current;

	current = *head;
	while (current)
	{
		if (!current->index)
			return (0);
		current = current->next;
	}
	return (1);
}

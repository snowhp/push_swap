/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:34:34 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/26 10:00:14 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

void	ft_otimizerotates(t_moves *moves)
{
	while (moves->ra >= 1 && moves->rb >= 1)
	{
		moves->ra--;
		moves->rb--;
		moves->rr++;
	}
	while (moves->rra >= 1 && moves->rrb >= 1)
	{
		moves->rra--;
		moves->rrb--;
		moves->rrr++;
	}
	moves->total += moves->ra;
	moves->total += moves->rb;
	moves->total += moves->rr;
	moves->total += moves->rra;
	moves->total += moves->rrb;
	moves->total += moves->rrr;
}

void	ft_initstruct(t_moves *moves)
{
	moves->ra = 0;
	moves->rb = 0;
	moves->rr = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->rrr = 0;
	moves->index = 0;
	moves->node = 0;
	moves->total = 0;
}

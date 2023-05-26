/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:56:04 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/26 10:01:42 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_bestmove(t_stack **head_a, t_stack **head_b)
{
	t_stack	*current;
	t_moves	moves;
	t_moves	best;
	t_stack	*match;

	ft_initstruct(&best);
	current = (*head_a);
	while (current)
	{
		ft_initstruct(&moves);
		moves.index = current->index;
		moves.node = current;
		if (ft_listsize(head_a) > 1)
			ft_crotates(current, head_a, &moves, 'a');
		match = ft_matchb(head_b, current->index);
		ft_crotates(match, head_b, &moves, 'b');
		ft_otimizerotates(&moves);
		if (best.index == 0)
			best = moves;
		if (moves.total < best.total)
			best = moves;
		current = current->next;
	}
	ft_execrotates(head_a, head_b, best);
}

void	ft_execrotates(t_stack **head_a, t_stack **head_b, t_moves moves)
{
	while (moves.ra)
	{
		ft_rotateup(head_a, 'a');
		moves.ra--;
	}
	while (moves.rb)
	{
		ft_rotateup(head_b, 'b');
		moves.rb--;
	}
	while (moves.rr)
	{
		ft_doublerotate(head_a, head_b);
		moves.rr--;
	}
	ft_execrotates2(head_a, head_b, moves);
}

void	ft_execrotates2(t_stack **head_a, t_stack **head_b, t_moves moves)
{
	while (moves.rra)
	{
		ft_rotatedown(head_a, 'a');
		moves.rra--;
	}
	while (moves.rrb)
	{
		ft_rotatedown(head_b, 'b');
		moves.rrb--;
	}
	while (moves.rrr)
	{
		ft_doublerevrotate(head_a, head_b);
		moves.rrr--;
	}
}

void	ft_crotates(t_stack *cu, t_stack **head_a, t_moves *moves, char c)
{
	int	pos;
	int	lsize;

	lsize = ft_listsize(head_a);
	pos = ft_listpos(cu, head_a);
	if (pos <= lsize / 2)
	{
		if (c == 'a')
			moves->ra = pos - 1;
		if (c == 'b')
			moves->rb = pos - 1;
	}
	else
	{
		if (c == 'a')
			moves->rra = lsize + 1 - pos;
		if (c == 'b')
			moves->rrb = lsize + 1 - pos;
	}
}

t_stack	*ft_matchb(t_stack **head_b, int index)
{
	t_stack	*current;
	t_stack	*match;
	t_stack	*max;

	current = (*head_b);
	match = ft_findmin(head_b);
	max = ft_findmax(head_b);
	if (index > max->index || index < match->index)
		return (max);
	while (current)
	{
		if (index > current->index && match->index < current->index)
			match = current;
		current = current->next;
	}
	return (match);
}

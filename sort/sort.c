/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:56:03 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/25 17:07:09 by tde-sous         ###   ########.fr       */
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
	t_stack	*max;

	ft_push(head_a, head_b, 'b');
	ft_push(head_a, head_b, 'b');
	while (ft_listsize(head_a) > 0)
	{
		ft_bestmove(head_a, head_b);
		ft_push(head_a, head_b, 'b');
	}
	max = ft_findmax(head_b);
	ft_autopush(max, head_b, head_a, 'a');
	while (ft_listsize(head_b) > 0)
		ft_push(head_b, head_a, 'a');
}

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
		match = ft_matchB(head_b, current->index);
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

t_stack	*ft_matchB(t_stack **head_b, int index)
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

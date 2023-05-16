/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:56:03 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/16 22:17:08 by tde-sous         ###   ########.fr       */
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
}

int     ft_listsize(t_stack **head_a)
{
    t_stack *current;
    int     size;

    size = 0;
    current = *head_a;
    while (current)
    {
        size++;
        current = current->next;
    }
    return (size);
}

void    ft_sort2(t_stack **head_a)
{
    if((*head_a)->next->content < (*head_a)->content)
        ft_rotatedown(head_a, 'a');
}

void    ft_sort3(t_stack **head)
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

int		ft_listsorted(t_stack **head)
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

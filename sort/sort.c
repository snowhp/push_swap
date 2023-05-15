/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:56:03 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/15 13:12:24 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ft_sortlist(t_stack **head_a, t_stack **head_b)
{
    int size;
    (void) head_b;

    size = ft_listsize(head_a);
    ft_printf("List size: %i\n", size);
    if(size == 2)
        ft_sort2(head_a);
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
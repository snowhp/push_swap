/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:37:06 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/26 13:53:05 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_push(t_stack **head_o, t_stack **head_d, char c)
{
	t_stack	*temp;

	if (!*head_o)
		return ;
	temp = *head_d;
	*head_d = *head_o;
	*head_o = (*head_o)->next;
	(*head_d)->next = temp;
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}

void	ft_swap(t_stack **head_1, char c)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (!(*head_1) || !(*head_1)->next)
		return ;
	temp = *head_1;
	temp2 = (*head_1)->next->next;
	*head_1 = (*head_1)->next;
	(*head_1)->next = temp;
	(*head_1)->next->next = temp2;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}

void	ft_rotateup(t_stack **head_1, char c)
{
	t_stack	*temp;
	t_stack	*current;

	if (!(*head_1) || !(*head_1)->next)
		return ;
	temp = *head_1;
	(*head_1) = (*head_1)->next;
	current = *head_1;
	while (current->next)
		current = current->next;
	current->next = temp;
	current->next->next = 0;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}

void	ft_rotatedown(t_stack **head_1, char c)
{
	t_stack	*current;

	if (!(*head_1) || !(*head_1)->next)
		return ;
	current = *head_1;
	while (current->next->next)
		current = current->next;
	current->next->next = *head_1;
	*head_1 = current->next;
	current->next = 0;
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}

void	ft_doublerotate(t_stack **head_a, t_stack **head_b)
{
	ft_rotateup(head_a, 0);
	ft_rotateup(head_b, 0);
	ft_printf("rr\n");
}

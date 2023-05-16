/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:49:48 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/16 22:16:21 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{

	t_stack *head_a;
	t_stack *head_b;

	if (argc == 1)
		return (0);
	/* Check input */
	/* Read input */
	check_arg(argv);
	head_a = 0;
	head_b = 0;
	ft_insertlist(&head_a, argv);
	ft_printf("Original list \n");
    printlist(&head_a, &head_b);
	ft_checkdups(&head_a);
    ft_sortlist(&head_a, &head_b);
    printlist(&head_a, &head_b);
	ft_printf("List is sorted? %i", ft_listsorted(&head_a));
	/* Check list for numbers, dups, intmax/min, already sorted*/
	/* ft_exit */
	/* Moves */
	/* Algorithm  */
	/* Check for dups, max min int */
}

void ft_insertlist(t_stack **head_a, char **argv)
{
	int 	x;
	int	nb;

	x = 1;
	while(argv[x])
	{
		nb = ft_atoi(argv[x++]);
		ft_addtail(head_a, nb);
	}
}

void	printlist(t_stack **head_a, t_stack **head_b)
{
	t_stack	*current;

	current = *head_a;
	while (current != NULL)
	{
		ft_printf("%d ", current->content);
		current = current->next;
	}
	ft_printf("A");
	ft_printf("\n");
	current = *head_b;
	while (current != NULL)
	{
		ft_printf("%d ", current->content);
		current = current->next;
	}
	ft_printf("B");
	ft_printf("\n");
}

void	ft_addtail(t_stack **head, long content)
{
	t_stack	*lst;
	t_stack *current = *head; // save pointer
	lst = malloc(sizeof(t_stack));
	if (!lst)
		return ;// exit
	lst->content = content;
	lst->next = NULL;
	// lista vazia
	if(!(*head))
	{
		free(*head);
		*head = lst;
		return ;
	}
	// list nao vazia percorrer ate ao proximo ser nullo Head A B |C|-> D
	while(current->next)
		current = current->next;
	current->next = lst;
}

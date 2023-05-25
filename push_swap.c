/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:49:48 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/25 13:03:00 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;

	if (argc == 1)
		return (0);
	head_a = 0;
	head_b = 0;
	ft_insertlist(&head_a, argv);
	//ft_printf("Original list \n");
	//printlist(&head_a, &head_b);
	ft_sortlist(&head_a, &head_b);
	printlist(&head_a, &head_b);
	if (!ft_listsorted(&head_a))
		ft_printf("List is sorted!");
	else
		ft_printf("List NOT sorted!");
	ft_exit(NULL, 0, &head_a, &head_b);
}

void	ft_insertlist(t_stack **head_a, char **argv)
{
	int	x;
	int	nb;

	x = 1;
	check_arg(argv);
	while (argv[x])
	{
		nb = ft_atoi(argv[x++]);
		ft_addtail(head_a, nb);
	}
	ft_checkdups(head_a);
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
	t_stack	*current;

	current = *head;
	lst = malloc(sizeof(t_stack));
	if (!lst)
		return ;
	lst->content = content;
	lst->next = NULL;
	lst->index = 0;
	if (!(*head))
	{
		free(*head);
		*head = lst;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = lst;
}

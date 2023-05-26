/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:49:48 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/26 09:54:15 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;
	char	**argv2;

	if (argc == 1)
		return (0);
	head_a = 0;
	head_b = 0;
	if (argv[1][0] == 0)
		return (0);
	if (argc == 2)
	{
		argv2 = ft_split(argv[1], ' ');
		if (argv2[0] == 0)
		{
			ft_freearray(argv2);
			ft_exit(0, &head_a, &head_b);
		}
		ft_insertlist(&head_a, argv2, 0);
		ft_freearray(argv2);
	}
	else
		ft_insertlist(&head_a, argv, 1);
	ft_sortlist(&head_a, &head_b);
	ft_exit(0, &head_a, &head_b);
}

void	ft_insertlist(t_stack **head_a, char **argv, int x)
{
	int	nb;

	ft_checkdigit(argv, x);
	ft_checkmax(argv, x);
	while (argv[x])
	{
		nb = ft_atoi(argv[x++]);
		ft_addtail(head_a, nb);
	}
	if (ft_listsize(head_a) == 0)
		ft_exit(1, head_a, NULL);
	if (ft_listsize(head_a) == 1)
		ft_exit(0, head_a, NULL);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:49:48 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/22 21:49:30 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_stack *head_a;
    t_stack *head_b;

    if (argc == 1)
        return 0;
    head_a = 0;
    head_b = 0;
    /* Read input */
    ft_listinput(argv, argc, &head_a);
    ft_printlist(*head_a);
    /* Check for dups, max min int */
}

void    ft_listinput(char **argv, int argc, t_stack **head_a)
{
    int    i;

    if (argc == 1)
        ft_listinput(ft_split(argv[1], ' '), ft_charsize(ft_split(argv[1], ' ')), head_a);
    else {
		i = 0;
		while (i < argc)
		{
			ft_lstnewd(head_a, ft_atol(argv[i++]));

		}
	}
}

int     ft_charsize(char **str)
{
    int     size;

    size = 0;
    while(str[size])
        size++;
    return (++size);
}

void    ft_printlist(t_stack head_a)
{
    ft_printf("%i", head_a.content);
    if(head_a.next)
        head_a = *head_a.next;
	else
	{
		ft_printlist(head_a);
		return ;
	}
    ft_printlist(head_a);
}

void	ft_lstnewd(t_stack **head, long content)
{
	t_stack	*lst;
	t_stack *current = *head; // save pointer
	lst = malloc(sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	// lista vazia
	(*head)->next = lst;
	// list nao vazia percorrer ate ao proximo ser nullo Head A B |C|-> D
	while()

}
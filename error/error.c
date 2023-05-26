/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:31:49 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/26 09:54:29 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_exit(int c, t_stack **head_a, t_stack **head_b)
{
	t_stack	*next;

	if (c != 0)
		ft_stderprint("Error\n");
	if (head_a)
	{
		while (*head_a != NULL)
		{
			next = (*head_a)->next;
			free(*head_a);
			*head_a = next;
		}
	}
	if (head_b)
	{
		while (*head_b != NULL)
		{
			next = (*head_b)->next;
			free(*head_b);
			*head_b = next;
		}
	}
	exit (c);
}

void	ft_freearray(char **str)
{
	int	x;

	x = 0;
	while (str[x])
		free(str[x++]);
	free(str);
}

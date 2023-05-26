/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:58:12 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/26 09:11:31 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	ft_checkdups(t_stack **head_a)
{
	t_stack	*current;
	t_stack	*i;

	current = *head_a;
	i = *head_a;
	while (current)
	{
		i = current->next;
		while (i)
		{
			if ((long)i->content == (long)current->content)
				ft_exit(1, head_a, NULL);
			i = i->next;
		}
		current = current->next;
	}
}

void	ft_checkmax(char **argv, int x)
{
	long	nb;

	while (argv[x])
	{
		nb = ft_atol(argv[x++]);
		if (nb < INT_MIN || nb > INT_MAX)
			ft_exit(1, NULL, NULL);
	}
}

void	ft_checkdigit(char **argv, int x)
{
	int	i;

	i = 0;
	while (argv[x])
	{
		i = 0;
		if (argv[x][i] == '-' && argv[x][i + 1])
			i++;
		while (argv[x][i])
		{
			if (ft_isdigit(argv[x][i]) == 0)
				ft_exit(1, NULL, NULL);
			i++;
		}
		x++;
	}
}

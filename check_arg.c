/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:58:12 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/16 21:22:51 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "inc/push_swap.h"

void check_arg(char **argv)
{
	ft_checkdigit(argv);
	ft_checkmax(argv);
}

void	ft_checkdups(t_stack **head_a)
{
	t_stack *current;
	t_stack *i;

	current = *head_a;
	i = *head_a;
	while (current)
	{
		i = current->next;
		while(i)
		{
			if((long)i->content == (long)current->content)
			{
				ft_printf("Dup numbers");
				exit(1);
			}
			i = i->next;
		}
		current = current->next;
	}
}

void	ft_checkmax(char **argv)
{
	long nb;
	int x;

	x = 1;
	while (argv[x])
	{
		nb = ft_atol(argv[x++]);
		if(nb < INT_MIN || nb > INT_MAX)
		{
			ft_printf("Arg not int");
			exit(1);
		}
	}
}

void ft_checkdigit(char **argv)
{
	int	i;
	int	x;

	x = 1;
	i = 0;
	while(argv[x]){
		i = 0;
		if(argv[x][i] == '-' && argv[x][i + 1])
			i++;
		while(argv[x][i]){
			if(ft_isdigit(argv[x][i]) == 0)
			{
				ft_printf("Arg not a digit");
				exit(1);
			}
			i++;
		}
		x++;
	}
}
